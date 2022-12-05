#ifndef KDTREE_HPP
#define KDTREE_HPP

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

/// @brief  class for representing a point. coordinate_type must be a numeric type
template <typename coordinate_type, size_t dimensions>
class Point
{
private:
    std::array<coordinate_type, dimensions> coords_;

public:
    /// @brief
    /// @param c
    Point(std::array<coordinate_type, dimensions> c) : coords_(c) {}

    /// @brief
    /// @param list
    Point(std::initializer_list<coordinate_type> list)
    {
        size_t n = std::min(dimensions, list.size());
        std::copy_n(list.begin(), n, coords_.begin());
    }

    /// @brief returns the coordinate in the given dimension
    /// @param index dimension index
    /// @return coordinate in the given dimension
    coordinate_type get(size_t index) const
    {
        return coords_[index];
    }
    /**
     * Returns the distance squared from this point to another
     * point.
     *
     * @param pnt another point
     * @return distance squared from this point to the other point
     */
    double distance(const Point &pnt) const
    {
        double dist = 0;
        for (size_t i = 0; i < dimensions; ++i)
        {
            double d = get(i) - pnt.get(i);
            dist += d * d;
        }
        return dist;
    }
};

template <typename coordinate_type, size_t dimensions>
std::ostream &operator<<(std::ostream &out, const Point<coordinate_type, dimensions> &pnt)
{
    out << '(';
    for (size_t i = 0; i < dimensions; ++i)
    {
        if (i > 0)
            out << ", ";
        out << pnt.get(i);
    }
    out << ')';
    return out;
}

/**
 * C++ k-d tree implementation, based on the C version at rosettacode.org.
 */
template <typename coordinate_type, size_t dimensions>
class kdtree
{
public:
    typedef Point<coordinate_type, dimensions> Point_type;

private:
    struct node
    {
        node(const Point_type &pnt) : point(pnt), left(nullptr), right(nullptr) {}
        coordinate_type get(size_t index) const
        {
            return point.get(index);
        }
        double distance(const Point_type &pnt) const
        {
            return point.distance(pnt);
        }
        Point_type point;
        node *left;
        node *right;
    };
    node *root = nullptr;
    node *best = nullptr;
    double best_dist_ = 0;
    size_t visited_ = 0;
    std::vector<node> nodes_;

    struct node_cmp
    {
        node_cmp(size_t index) : index_(index) {}
        bool operator()(const node &n1, const node &n2) const
        {
            return n1.point.get(index_) < n2.point.get(index_);
        }
        size_t index_;
    };

    node *make_tree(size_t begin, size_t end, size_t index)
    {
        if (end <= begin)
            return nullptr;
        size_t n = begin + (end - begin) / 2;
        auto i = nodes_.begin();
        std::nth_element(i + begin, i + n, i + end, node_cmp(index));
        index = (index + 1) % dimensions;
        nodes_[n].left = make_tree(begin, n, index);
        nodes_[n].right = make_tree(n + 1, end, index);
        return &nodes_[n];
    }

    void nearest(node *root, const Point_type &Point, size_t index)
    {
        if (root == nullptr)
            return;
        ++visited_;
        double d = root->distance(Point);
        if (best == nullptr || d < best_dist_)
        {
            best_dist_ = d;
            best = root;
        }
        if (best_dist_ == 0)
            return;
        double dx = root->get(index) - Point.get(index);
        index = (index + 1) % dimensions;
        nearest(dx > 0 ? root->left : root->right, Point, index);
        if (dx * dx >= best_dist_)
            return;
        nearest(dx > 0 ? root->right : root->left, Point, index);
    }

public:
    kdtree(const kdtree &) = delete;
    kdtree &operator=(const kdtree &) = delete;
    /**
     * Constructor taking a pair of iterators. Adds each
     * Point in the range [begin, end) to the tree.
     *
     * @param begin start of range
     * @param end end of range
     */
    template <typename iterator>
    kdtree(iterator begin, iterator end) : nodes_(begin, end)
    {
        root = make_tree(0, nodes_.size(), 0);
    }

    /**
     * Constructor taking a function object that generates
     * Points. The function object will be called n times
     * to populate the tree.
     *
     * @param f function that returns a Point
     * @param n number of Points to add
     */
    template <typename func>
    kdtree(func &&f, size_t n)
    {
        nodes_.reserve(n);
        for (size_t i = 0; i < n; ++i)
            nodes_.push_back(f());
        root = make_tree(0, nodes_.size(), 0);
    }

    /**
     * Returns true if the tree is empty, false otherwise.
     */
    bool empty() const { return nodes_.empty(); }

    /**
     * Returns the number of nodes visited by the last call
     * to nearest().
     */
    size_t visited() const { return visited_; }

    /**
     * Returns the distance between the input Point and return value
     * from the last call to nearest().
     */
    double distance() const { return std::sqrt(best_dist_); }

    /**
     * Finds the nearest Point in the tree to the given Point.
     * It is not valid to call this function if the tree is empty.
     *
     * @param pnt a Point
     * @return the nearest Point in the tree to the given Point
     */
    const Point_type &nearest(const Point_type &pnt)
    {
        if (root == nullptr)
            throw std::logic_error("tree is empty");
        best = nullptr;
        visited_ = 0;
        best_dist_ = 0;
        nearest(root, pnt, 0);
        return best->point;
    }
};

#endif