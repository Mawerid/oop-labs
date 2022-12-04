#include "../include/field.hpp"

namespace field
{
    Node::Node(const Cell &root_info)
    {
    }

    Node::Node(const Node &tree)
    {
    }

    Node::Node(Node &&tree)
    {
    }

    Node::~Node()
    {

    }

    Cell Node::get_info() { return info; }

    void Node::set_info(const Cell &cell_info)    {  info = cell_info;  }

    Node *Node::insert(Node *root, const Cell &cell_info)
    {
    }

    Node *Node::insert(Node *root, const Cell &cell_info, const unsigned &n)
    {
    }

    Node *Node::search(Node *root, const Cell &cell_info)
    {
    }

    Node *Node::search(Node *root, const Cell &cell_info, const unsigned &n)
    {
    }

    Node *Node::find_min(Node *root, const dimension &cell_info)
    {
    }

    Node *Node::find_min(Node *root, const dimension &cell_info, const unsigned &n)
    {
    }

    Node *Node::delete_node(Node *root, const Cell &cell_info)
    {
    }

    Node *Node::delete_node(Node *root, const Cell &cell_info, const unsigned &n)
    {
    }

    void Node::swap(Node *node_1, Node *node_2)
    {
    }
}