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

    /// Cell class

    Cell::Cell() 
    {
        type = cell_type::FREE;
        coor = new point;
    }

    Cell::Cell(const cell_type &type_new) 
    {
        type = type_new;
        coor = new point;
    }

    Cell::Cell(point *coor_new)
    {
        type = cell_type::FREE;
        coor = new point;
        coor->set_x(coor_new->get_x());
        coor->set_y(coor_new->get_y());
    }

    Cell::Cell(point *coor_new, const cell_type &type_new, squad::Squad *fill): type(type_new), filling(fill), coor(coor_new) {}

    Cell::Cell(const Cell &old_cell)
    {
        type = old_cell.type;
        coor = new point;
        coor->set_x(old_cell.coor->get_x());
        coor->set_y(old_cell.coor->get_y());
        filling = new squad::Squad(*old_cell.filling);
    }

    Cell::Cell(Cell &&old_cell)
    {
        type = old_cell.type;
        filling = old_cell.filling;
        coor = old_cell.coor;
        old_cell.filling = nullptr;
        old_cell.coor = nullptr;
    }

    Cell::~Cell()
    {
        if (coor != nullptr)
            delete coor;
        
        filling = nullptr;
    }

    cell_type Cell::get_type() const { return type; }

    squad::Squad *Cell::get_filling() const { return filling; }

    point *Cell::get_coor() const { return coor; }

    void Cell::set_type(const cell_type &type_new) { type = type_new; }

    void Cell::set_filling(squad::Squad *fill) { filling = fill; }

    void Cell::set_coor(point *coor_new) { coor = coor_new; }

    bool Cell::operator==(const Cell &other_cell) const
    {
        if (*coor == *(other_cell.coor) && type == other_cell.type)
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