#ifndef KDTREE_H
#define KDTREE_H

#include <vector>
#include <memory>
#include <numeric>
#include <iostream>

namespace std
{
    /// @brief  class of node in KD-tree
    /// @tparam PointType
    /// @tparam SplitDimension
    template <typename PointType, int SplitDimension>
    class Node
    {
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
    class KDTree
    {
    private:
        std::unique_ptr<Node<PointType, 0>> root;
        PointArray points;
        std::vector<size_t> pointIndeces;

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
        void dumpSubtree(std::unique_ptr<Node<PointType, SplitDimension>> &node);

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
        static bool pointInRange(PointType testPoint, double queryRange[2 * PointType::dimension])
        {
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

/*
        /// @brief  
        /// @tparam function
        /// @tparam SplitDimension
        /// @param func 
        /// @param node subtree's root
        template <int SplitDimension, typename function>
        void inorderTraversalSubtree(function func, std::unique_ptr<Node<PointType, SplitDimension>> &node);
*/
        /// @brief  insertion in tree
        /// @tparam SplitDimension
        /// @param node root of subtree
        /// @param pointIndex   index of point
        /// @return new root of subtree
        template <int SplitDimension>
        std::unique_ptr<Node<PointType, SplitDimension>> insertPointSubtree(std::unique_ptr<Node<PointType, SplitDimension>> &node, size_t pointIndex);

    public:
        /// @brief  constructor
        KDTree() {}

        /// @brief  constructor
        /// @param pointsIn array of points
        KDTree(const PointArray &pointsIn) { buildTree(pointsIn); }

        /// @brief  func, that make tree from array of points
        /// @param pointsIn array of points
        void buildTree(const PointArray &pointsIn);

        /// @brief  print all tree
        void dumpTreeInorder();

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
        void dumpNode(size_t i) { std::cout << points[i] << std::endl; }

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
}

#endif