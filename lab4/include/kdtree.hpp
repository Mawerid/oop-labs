#ifndef KDTREE_H
#define KDTREE_H

#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

namespace std {
/// @brief  class of node in KD-tree
/// @tparam PointType
/// @tparam SplitDimension
template <typename PointType, int SplitDimension>
class Node {
   public:
    typedef Node<PointType, (SplitDimension + 1) % PointType::dimension> ChildType;

    Node(size_t ind) : treeIndex(ind) {}
    size_t treeIndex;

    std::unique_ptr<ChildType> leftChild, rightChild;
};

/// @brief  class of KD-tree template
/// @tparam PointType
/// @tparam PointArray
template <typename PointType, typename PointArray = std::vector<PointType>>
class KDTree {
   private:
    std::unique_ptr<Node<PointType, 0>> root;
    PointArray points;
    std::vector<size_t> pointIndexes;

    /// @brief  fubction to build tree from vector iterator
    /// @tparam SplitDimension
    /// @param begin    begin iterator
    /// @param end  end iterator
    /// @return pointer to KD tree
    template <int SplitDimension>
    std::unique_ptr<Node<PointType, SplitDimension>> buildSubtree(std::vector<size_t>::iterator begin, std::vector<size_t>::iterator end);

    /// @brief  print tree
    /// @tparam SplitDimension
    /// @param node tree to print
    template <int SplitDimension>
    std::ostream &dumpSubtree(std::unique_ptr<Node<PointType, SplitDimension>> &node, std::ostream &cout);

    /// @brief  func, that return subtree's points, that in cube
    /// @tparam SplitDimension
    /// @param testPoint    central point
    /// @param queryRange   K dimention range
    /// @param node subtree
    /// @param ret  return value
    template <int SplitDimension>
    void getPointsWithinCubeSubtree(PointType testPoint, double queryRange[2 * PointType::dimension], std::unique_ptr<Node<PointType, SplitDimension>> &node, std::vector<size_t> &ret);

    /// @brief  check if point in range (in K dimention)
    /// @param testPoint    point to check
    /// @param queryRange   K dimention range
    /// @return is point in range or not
    static bool pointInRange(PointType testPoint, double queryRange[2 * PointType::dimension]) {
        for (int i = 0; i < PointType::dimension; ++i)
            if (testPoint.getDimension(i) < queryRange[2 * i] || testPoint.getDimension(i) > queryRange[2 * i + 1])
                return false;

        return true;
    }

    /// @brief  function, that find minimum value in subtree
    /// @tparam SplitDimension
    /// @param dimension    dimention of value
    /// @param node subtree's root
    /// @return minimum value
    template <int SplitDimension>
    size_t findMinSubtree(int dimension, std::unique_ptr<Node<PointType, SplitDimension>> &node);

    /// @brief  delete node from subtree
    /// @tparam SplitDimension
    /// @param nodeIndex    index of node
    /// @param node node to delete
    /// @return new root of subtree
    template <int SplitDimension>
    std::unique_ptr<Node<PointType, SplitDimension>> deleteFromSubtree(size_t nodeIndex, std::unique_ptr<Node<PointType, SplitDimension>> &node);

    /// @brief  insertion in tree
    /// @tparam SplitDimension
    /// @param node root of subtree
    /// @param pointIndex   index of point
    /// @return new root of subtree
    template <int SplitDimension>
    std::unique_ptr<Node<PointType, SplitDimension>> insertPointSubtree(std::unique_ptr<Node<PointType, SplitDimension>> &node, size_t pointIndex);

   public:
    template <typename ValueType>
    class TreeIterator : public std::iterator<std::input_iterator_tag, ValueType> {
        friend class KDTree;

       private:
        TreeIterator(ValueType *p) : p(p){};
        ValueType *p;

       public:
        TreeIterator(const TreeIterator &it) : p(it.p){};

        bool operator!=(TreeIterator const &other) const {
            return p != other.p;
        }

        bool operator==(TreeIterator const &other) const {
            return p == other.p;
        }

        typename TreeIterator::value_type *operator->() const {
            return &p;
        }

        typename TreeIterator::reference operator*() const {
            return *p;
        }

        TreeIterator &operator++() {
            ++p;
            return *this;
        }
    };

    typedef TreeIterator<PointType> iterator;
    typedef TreeIterator<const PointType> const_iterator;

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;

    /// @brief  constructor
    KDTree() {}

    /// @brief  constructor
    /// @param pointsIn array of points
    KDTree(const PointArray &pointsIn) { buildTree(pointsIn); }

    /// @brief  func, that make tree from array of points
    /// @param pointsIn array of points
    void buildTree(const PointArray &pointsIn);

    /// @brief  print all tree
    /// @param cout output stream
    /// @return output stream
    std::ostream &dumpTreeInorder(std::ostream &cout);

    /// @brief  make inorder traversal with function
    /// @tparam function
    /// @param func function
    template <typename function>
    void inorderTraversal(function func);

    /// @brief  function that return points in some cube
    /// @param testPoint    central point
    /// @param radius   radius of area
    /// @return vector with all points in cube
    std::vector<size_t> getPointsWithinCube(PointType testPoint, double radius);

    /// @brief  find minimal
    /// @param dimension    in which dimension
    /// @return index of minimal
    size_t findMin(int dimension);

    /// @brief  print node
    /// @param i   index of node
    std::ostream &dumpNode(size_t i, std::ostream &cout) {
        cout << points[i] << std::endl;
        return cout;
    }

    /// @brief  delete point
    /// @param nodeIndex    index of point to delete
    void deletePoint(size_t nodeIndex);

    /// @brief  get point from index
    /// @param nodeIndex    index of point
    /// @return point
    PointType getPoint(size_t nodeIndex) { return points[nodeIndex]; }

    /// @brief  insertion in tree
    /// @param p    point to insert
    void insertPoint(const PointType &p);
};

template <typename PointType, typename PointArray>
void KDTree<PointType, PointArray>::buildTree(const PointArray &pointsIn) {
    points = pointsIn;
    pointIndexes.resize(points.size());
    std::iota(pointIndexes.begin(), pointIndexes.end(), 0);
    root = buildSubtree<0>(pointIndexes.begin(), pointIndexes.end());
}

template <typename PointType, typename PointArray>
template <int SplitDimension>
std::unique_ptr<Node<PointType, SplitDimension>> KDTree<PointType, PointArray>::buildSubtree(std::vector<size_t>::iterator begin, std::vector<size_t>::iterator end) {
    auto rangeSize = std::distance(begin, end);

    if (rangeSize == 0)
        return std::unique_ptr<Node<PointType, SplitDimension>>(nullptr);
    else {
        std::sort(begin, end, [this](size_t a, size_t b) { return points[a].getDimension(SplitDimension) < points[b].getDimension(SplitDimension); });
        auto median = begin + rangeSize / 2;
        while (median != begin && points[*(median)].getDimension(SplitDimension) == points[*(median - 1)].getDimension(SplitDimension))
            --median;

        auto ret = std::unique_ptr<Node<PointType, SplitDimension>>(new Node<PointType, SplitDimension>(*median));

        ret->leftChild = buildSubtree<(SplitDimension + 1) % PointType::dimension>(begin, median);
        ret->rightChild = buildSubtree<(SplitDimension + 1) % PointType::dimension>(median + 1, end);

        return ret;
    }
}

template <typename PointType, typename PointArray>
std::ostream &KDTree<PointType, PointArray>::dumpTreeInorder(std::ostream &cout) {
    dumpSubtree<0>(root, cout);
    return cout;
}

template <typename PointType, typename PointArray>
template <int SplitDimension>
std::ostream &KDTree<PointType, PointArray>::dumpSubtree(std::unique_ptr<Node<PointType, SplitDimension>> &node, std::ostream &cout) {
    if (node->leftChild) {
        cout << "dumping left: " << std::endl;
        dumpSubtree<(SplitDimension + 1) % PointType::dimension % 3>(node->leftChild, cout);
    }
    cout << "dumping this: " << std::endl;
    cout << node->treeIndex << ": " << points[node->treeIndex] << std::endl;
    if (node->rightChild) {
        cout << "dumping right: " << std::endl;
        dumpSubtree<(SplitDimension + 1) % PointType::dimension % 3>(node->rightChild, cout);
    }
    return cout;
}

template <typename PointType, typename PointArray>
std::vector<size_t> KDTree<PointType, PointArray>::getPointsWithinCube(PointType testPoint, double radius) {
    double queryRange[2 * PointType::dimension];
    for (auto i = 0; i < PointType::dimension; ++i) {
        queryRange[2 * i] = testPoint.getDimension(i) - radius;
        queryRange[2 * i + 1] = testPoint.getDimension(i) + radius;
    }

    std::vector<size_t> ret;
    getPointsWithinCubeSubtree<0>(testPoint, queryRange, root, ret);

    return ret;
}

template <typename PointType, typename PointArray>
template <int SplitDimension>
void KDTree<PointType, PointArray>::getPointsWithinCubeSubtree(PointType testPoint, double queryRange[2 * PointType::dimension], std::unique_ptr<Node<PointType, SplitDimension>> &node, std::vector<size_t> &ret) {
    if (node == nullptr)
        return;

    auto nodePoint = points[node->treeIndex];
    if (pointInRange(nodePoint, queryRange))
        ret.push_back(node->treeIndex);

    if (nodePoint.getDimension(SplitDimension) >= queryRange[2 * SplitDimension])
        getPointsWithinCubeSubtree<(SplitDimension + 1) % PointType::dimension>(testPoint, queryRange, node->leftChild, ret);

    if (nodePoint.getDimension(SplitDimension) <= queryRange[2 * SplitDimension + 1])
        getPointsWithinCubeSubtree<(SplitDimension + 1) % PointType::dimension>(testPoint, queryRange, node->rightChild, ret);
}

template <typename PointType, typename PointArray>
size_t KDTree<PointType, PointArray>::findMin(int dimension) { return findMinSubtree<0>(dimension, root); }

template <typename PointType, typename PointArray>
template <int SplitDimension>
size_t KDTree<PointType, PointArray>::findMinSubtree(int dimension, std::unique_ptr<Node<PointType, SplitDimension>> &node) {
    if (SplitDimension == dimension) {
        if (node->leftChild == nullptr)
            return node->treeIndex;
        else
            return findMinSubtree<(SplitDimension + 1) % PointType::dimension>(dimension, node->leftChild);
    } else {
        size_t leftMin = 123456, rightMin = 123456;
        if (node->leftChild)
            leftMin = findMinSubtree<(SplitDimension + 1) % PointType::dimension>(dimension, node->leftChild);
        if (node->rightChild)
            rightMin = findMinSubtree<(SplitDimension + 1) % PointType::dimension>(dimension, node->rightChild);

        auto nodeValue = points[node->treeIndex].getDimension(dimension);
        if (node->leftChild && points[leftMin].getDimension(dimension) < nodeValue) {
            if (node->rightChild)
                return (points[leftMin].getDimension(dimension) < points[rightMin].getDimension(dimension)) ? leftMin : rightMin;
            else
                return leftMin;
        } else if (node->rightChild && points[rightMin].getDimension(dimension) < nodeValue)
            return rightMin;
        else
            return node->treeIndex;
    }
}

template <typename PointType, typename PointArray>
void KDTree<PointType, PointArray>::deletePoint(size_t nodeIndex) { root = deleteFromSubtree<0>(nodeIndex, root); }

template <typename PointType, typename PointArray>
template <int SplitDimension>
std::unique_ptr<Node<PointType, SplitDimension>> KDTree<PointType, PointArray>::deleteFromSubtree(size_t nodeIndex, std::unique_ptr<Node<PointType, SplitDimension>> &node) {
    constexpr size_t nextDimension = (SplitDimension + 1) % PointType::dimension;

    if (node->treeIndex == nodeIndex) {
        if (node->rightChild) {
            auto rightMin = findMinSubtree<nextDimension>(SplitDimension, node->rightChild);
            node->treeIndex = rightMin;
            node->rightChild = deleteFromSubtree<nextDimension>(rightMin, node->rightChild);
        } else if (node->leftChild) {
            auto leftMin = findMinSubtree<nextDimension>(SplitDimension, node->leftChild);
            node->treeIndex = leftMin;
            node->rightChild = deleteFromSubtree<nextDimension>(leftMin, node->leftChild);
            node->leftChild = nullptr;
        } else
            return nullptr;
    } else if (points[nodeIndex].getDimension(SplitDimension) < points[node->treeIndex].getDimension(SplitDimension))
        node->leftChild = deleteFromSubtree<nextDimension>(nodeIndex, node->leftChild);
    else
        node->rightChild = deleteFromSubtree<nextDimension>(nodeIndex, node->rightChild);

    return std::move(node);
}

template <typename PointType, typename PointArray>
void KDTree<PointType, PointArray>::insertPoint(const PointType &point) {
    points.push_back(point);
    root = insertPointSubtree<0>(root, points.size() - 1);
}

template <typename PointType, typename PointArray>
template <int SplitDimension>
std::unique_ptr<Node<PointType, SplitDimension>> KDTree<PointType, PointArray>::insertPointSubtree(std::unique_ptr<Node<PointType, SplitDimension>> &node, size_t pointIndex) {
    auto constexpr nextDimension = (SplitDimension + 1) % PointType::dimension;

    if (node == nullptr)
        return std::unique_ptr<Node<PointType, SplitDimension>>(new Node<PointType, SplitDimension>(pointIndex));
    else if (points[pointIndex].getDimension(SplitDimension) < points[node->treeIndex].getDimension(SplitDimension))
        node->leftChild = insertPointSubtree<nextDimension>(node->leftChild, pointIndex);
    else
        node->rightChild = insertPointSubtree<nextDimension>(node->rightChild, pointIndex);

    return std::move(node);
}

template <typename PointType, typename PointArray>
KDTree<PointType, PointArray>::iterator KDTree<PointType, PointArray>::begin() {
    auto ptr = root;
    auto parent = root;
    for (; ptr->leftChild != nullptr; ptr = ptr->leftChild)
        parent = ptr;

    return iterator(parent);
}

template <typename PointType, typename PointArray>
KDTree<PointType, PointArray>::iterator KDTree<PointType, PointArray>::end() {
    auto ptr = root;
    auto parent = root;
    for (; ptr->rightChild != nullptr; ptr = ptr->rightChild)
        parent = ptr;

    return iterator(parent);
}

template <typename PointType, typename PointArray>
KDTree<PointType, PointArray>::const_iterator KDTree<PointType, PointArray>::begin() const {
    auto ptr = root;
    auto parent = root;
    for (; ptr->leftChild != nullptr; ptr = ptr->leftChild)
        parent = ptr;

    return const_iterator(parent);
}

template <typename PointType, typename PointArray>
KDTree<PointType, PointArray>::const_iterator KDTree<PointType, PointArray>::end() const {
    auto ptr = root;
    auto parent = root;
    for (; ptr->rightChild != nullptr; ptr = ptr->rightChild)
        parent = ptr;

    return const_iterator(parent);
}
}  // namespace std

#endif