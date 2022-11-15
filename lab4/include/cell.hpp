#ifndef CELL_HPP
#define CELL_HPP

#include <math.h>
#include "squad.hpp"

namespace field
{
    enum cell_type
    {
        FREE,
        BUSY,
        OBSTAClE
    };

    class point
    {
    private:
        size_t coor_x;
        size_t coor_y;

    public:
        point();
        point(const size_t, const size_t);
        point(const point &);
        point(point &&);

        void set_x(const size_t &);
        void set_y(const size_t &);
        size_t get_x();
        size_t get_y();

        double distance(const point &, const point &);

        bool operator==(const point &);
    };

    class cell
    {
    private:
        cell_type type;
        squad::squad *filling = nullptr;
        point coor;

    public:
        cell();
        cell(const cell_type &);
        cell(const point &);
        cell(const point &, const cell_type &, squad::squad *fill = nullptr);
        cell(const cell &);
        cell(cell &&);

        ~cell();

        cell_type get_type();
        squad::squad *get_filling();
        point get_coor();

        void set_type(const cell_type &);
        void set_filling(squad::squad *);
        void set_coor(const point &);

        bool operator==(const cell &);
    };
}

#endif