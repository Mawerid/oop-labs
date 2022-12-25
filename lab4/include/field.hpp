#ifndef FIELD_HPP
#define FIElD_HPP

#include "cell.hpp"
#include <map>

namespace field
{
    enum class dimension
    {
        X,
        Y
    };

    /// @brief  class of field (in 2D tree)
    class Node
    {
    private:
        Cell info;
        Node *left;
        Node *right;

    public:
        /// @brief  constructor
        /// @param root_info    root's cell
        Node(const Cell &root_info);

        /// @brief  copy constructor
        /// @param tree tree to copy
        Node(const Node &tree);

        /// @brief  move constructor
        /// @param tree tree to move
        Node(Node &&tree);

        ~Node();

        /// @brief  getter of info(cell) of node
        /// @return info(cell)
        Cell get_info();

        /// @brief  setter of info(cell) of node
        /// @param cell_info    info(cell)
        void set_info(const Cell &cell_info);

        /// @brief  insertion in tree
        /// @param root root of tree
        /// @param cell_info    cell to insert
        /// @return new root
        Node *insert(Node *root, const Cell &cell_info);

        /// @brief  recursive insertion in tree (help function)
        /// @param root root of tree
        /// @param cell_info    cell to insert
        /// @param n    depth in tree
        /// @return new root node
        Node *insert(Node *root, const Cell &cell_info, const unsigned &n);

        /// @brief  search in tree
        /// @param root root of tree
        /// @param cell_info    cell to search
        /// @return new root
        Node *search(Node *root, const Cell &cell_info);

        /// @brief  recursive search in tree (help function)
        /// @param root root of tree
        /// @param cell_info    cell to search
        /// @param n    depth in tree
        /// @return new root node
        Node *search(Node *root, const Cell &cell_info, const unsigned &n);

        /// @brief  find minimal in tree
        /// @param root root of tree
        /// @param cell_info    cell to find min
        /// @return new root
        Node *find_min(Node *root, const dimension &cell_info);

        /// @brief  recursive find minimal in tree (help function)
        /// @param root root of tree
        /// @param cell_info    cell to find
        /// @param n    depth in tree
        /// @return new root node
        Node *find_min(Node *root, const dimension &cell_info, const unsigned &n);

        /// @brief  delete in tree
        /// @param root root of tree
        /// @param cell_info    cell to delete
        /// @return new root
        Node *delete_node(Node *root, const Cell &cell_info);

        /// @brief  recursive delete in tree (help function)
        /// @param root root of tree
        /// @param cell_info    cell to delete
        /// @param n    depth in tree
        /// @return new root node
        Node *delete_node(Node *root, const Cell &cell_info, const unsigned &n);

        /// @brief  swapping function of two nodes
        /// @param node_1   node from
        /// @param node_2   mode to
        void swap(Node *node_1, Node *node_2);
    };
}

#endif