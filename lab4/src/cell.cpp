#include "../include/cell.hpp"

namespace field
{
    point::point() : coor_x(0), coor_y(0) {}

    point::point(const size_t x, const size_t y) : coor_x(x), coor_y(y) {}

    point::point(const point &pnt)
    {
        coor_x = pnt.get_x();
        coor_y = pnt.get_y();
    }

    point::point(point &&pnt)
    {
        coor_x = pnt.coor_x;
        coor_y = pnt.coor_y;
    }

    void point::set_x(const size_t &x) { coor_x = x; }

    void point::set_y(const size_t &y) { coor_y = y; }

    size_t point::get_x() const { return coor_x; }

    size_t point::get_y() const { return coor_y; }

    double point::distance(const point &pnt) const
    {
        double dist;

        dist = pow((coor_x - pnt.get_x()), 2) + pow((coor_y - pnt.get_y()), 2);
        dist = sqrt(dist);

        return dist;
    }

    bool point::operator==(const point &pnt) const
    {
        if (coor_x == pnt.get_x() && coor_y == pnt.get_y())
            return true;
        else
            return false;
    }

    point point::operator=(const point &pnt)
    {
        coor_x = pnt.get_x();
        coor_y = pnt.get_y();

        return *this;
    }

    /// Cell class

    Cell::Cell()
    {
        type = cell_type::FREE;
        coor = point();
    }

    Cell::Cell(const cell_type &type_new)
    {
        type = type_new;
        coor = point();
    }

    Cell::Cell(const point coor_new)
    {
        type = cell_type::FREE;
        coor = coor_new;
    }

    Cell::Cell(const point coor_new, const cell_type &type_new, squad::Squad *fill) : type(type_new), filling(fill), coor(coor_new) {}

    Cell::Cell(const Cell &old_cell)
    {
        type = old_cell.type;
        coor = old_cell.coor;
        filling = new squad::Squad(*old_cell.filling);
    }

    Cell::Cell(Cell &&old_cell)
    {
        type = old_cell.type;
        filling = old_cell.filling;
        coor = old_cell.coor;
        old_cell.filling = nullptr;
    }

    Cell::Cell(const size_t &coor_x, const size_t &coor_y, const cell_type &c_type, squad::Squad *fill)
    {
        type = c_type;
        coor = point(coor_x, coor_y);
        filling = fill;
    }

    Cell::~Cell()
    {
        filling = nullptr;
    }

    cell_type Cell::get_type() const { return type; }

    squad::Squad *Cell::get_filling() const { return filling; }

    point Cell::get_coor() const { return coor; }

    void Cell::set_type(const cell_type &type_new) { type = type_new; }

    void Cell::set_filling(squad::Squad *fill) { filling = fill; }

    void Cell::set_coor(const point &coor_new) { coor = coor_new; }

    bool Cell::operator==(const Cell &other_cell) const
    {
        if (coor == other_cell.coor && type == other_cell.type)
            return true;
        else
            return false;
    }

    Cell Cell::operator=(Cell cell)
    {
        type = cell.type;
        filling = cell.filling;
        coor = cell.coor;

        return *this;
    }
}