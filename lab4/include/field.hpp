#ifndef FIELD_HPP
#define FIElD_HPP

#include "cell.hpp"

namespace field
{
    enum class dimension
    {
        X,
        Y
    };

    /// @brief
    class Node
    {
    private:
        Cell info;
        Node *left;
        Node *right;

    public:
        /// @brief
        /// @param root_info
        Node(const Cell &root_info);

        /// @brief
        /// @param tree
        Node(const Node &tree);

        /// @brief 
        /// @param tree 
        Node(Node &&tree);

        ~Node();

        /// @brief 
        /// @return 
        Cell get_info();

        /// @brief 
        /// @param cell_info 
        void set_info(const Cell &cell_info);

        /// @brief 
        /// @param root 
        /// @param cell_info 
        /// @return 
        Node *insert(Node *root, const Cell &cell_info);

        /// @brief 
        /// @param root 
        /// @param cell_info 
        /// @param n 
        /// @return 
        Node *insert(Node *root, const Cell &cell_info, const unsigned &n);

        /// @brief 
        /// @param root 
        /// @param cell_info 
        /// @return 
        Node *search(Node *root, const Cell &cell_info);

        /// @brief 
        /// @param root 
        /// @param cell_info 
        /// @param n 
        /// @return 
        Node *search(Node *root, const Cell &cell_info, const unsigned &n);

        /// @brief 
        /// @param root 
        /// @param cell_info 
        /// @return 
        Node *find_min(Node *root, const dimension &cell_info);

        /// @brief 
        /// @param root 
        /// @param cell_info 
        /// @param n 
        /// @return 
        Node *find_min(Node *root, const dimension &cell_info, const unsigned &n);

        /// @brief 
        /// @param root 
        /// @param cell_info 
        /// @return 
        Node *delete_node(Node *root, const Cell &cell_info);

        /// @brief 
        /// @param root 
        /// @param cell_info 
        /// @param n 
        /// @return 
        Node *delete_node(Node *root, const Cell &cell_info, const unsigned &n);

        /// @brief 
        /// @param node_1 
        /// @param node_2 
        void swap(Node *node_1, Node *node_2);
    };
}

#endif