#ifndef FIELD_HPP
#define FIElD_HPP

#include "cell.hpp"

namespace field
{
    enum dimension
    {
        X,
        Y
    };

    class node
    {
    private:
        cell info;
        node *left;
        node *right;

    public:
        node(const cell &);
        node(const node &);
        node(node&&);

        cell get_info();
        void set_info(const cell &);

        node *insert(node *, const cell &);
        node *insert(node *, const cell &, const unsigned &);

        node *search(node *, const cell &);
        node *search(node *, const cell &, const unsigned &);

        node *find_min(node *, const dimension &);
        node *find_min(node *, const dimension &, const unsigned &);

        node *delete_node(node *, const cell &);
        node *delete_node(node *, const cell &, const unsigned &);
    };
}

#endif