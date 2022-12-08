#ifndef CELL_HPP
#define CELL_HPP

#include <math.h>
#include "squad.hpp"

namespace field
{
    /// @brief  3 types of Cell in field
    enum class cell_type
    {
        FREE,
        BUSY,
        OBSTAClE
    };

    /// @brief  class describing common point
    class point
    {
    private:
        size_t coor_x;
        size_t coor_y;

    public:
        /// @brief  empty constructor
        point();

        /// @brief  constuctor
        /// @param x    x coordinate of point
        /// @param y    y coordinate of point
        point(const size_t x, const size_t y);

        /// @brief  copy constructor
        /// @param pnt  other point
        point(const point &pnt);

        /// @brief  move constructor
        /// @param pnt  other point
        point(point &&pnt);

        /// @brief  setter of x coordinate
        /// @param x    new x coordinate of point
        void set_x(const size_t &x);

        /// @brief  setter of y coordinate
        /// @param y    new y coordinate of point
        void set_y(const size_t &y);

        /// @brief  getter of x coordinate
        /// @return x coordinate
        size_t get_x() const;

        /// @brief  getter of y coordinate
        /// @return y coordinate
        size_t get_y() const;

        /// @brief  calculate distance between two points
        /// @param point_1  first point
        /// @param point_2  second point
        /// @return distance between two points
        double distance(const point &pnt) const;

        /// @brief  compare two points
        /// @param pnt point to compare
        /// @return is two points are equal
        bool operator==(const point &pnt) const;

        /// @brief
        /// @param pnt point to copy
        /// @return
        point operator=(const point &pnt);
    };

    /// @brief class describing a Cell in the game field
    class Cell
    {
    private:
        cell_type type;
        point coor;
        squad::Squad *filling = nullptr;

    public:
        /// @brief  empty constructor
        Cell();

        /// @brief  constructor
        /// @param c_type type of Cell
        Cell(const cell_type &c_type);

        /// @brief  constructor
        /// @param coor_new    coordinates of Cell in field
        Cell(const point coor_new);

        /// @brief  constructor
        /// @param coor_new    coordinates of Cell in field
        /// @param type type of Cell
        /// @param fill filling of the Cell
        Cell(const point coor_new, const cell_type &c_type, squad::Squad *fill);

        /// @brief
        /// @param coor_x
        /// @param coor_y
        /// @param c_type
        /// @param fill
        Cell(const size_t &coor_x, const size_t &coor_y, const cell_type &c_type, squad::Squad *fill);

        /// @brief  copy constructor
        /// @param old_cell Cell to copy
        Cell(const Cell &old_cell);

        /// @brief  move constructor
        /// @param old_cell Cell to move
        Cell(Cell &&old_cell);

        ~Cell();

        /// @brief  getter of the type
        /// @return type of Cell
        cell_type get_type() const;

        /// @brief  getter of the filling
        /// @return pointer to filling squad of Cell
        squad::Squad *get_filling() const;

        /// @brief  getter of the coordinates of Cell
        /// @return point contains coordinates of Cell
        point get_coor() const;

        /// @brief  setter of the Cell type
        /// @param type new type of Cell
        void set_type(const cell_type &c_type);

        /// @brief  setter of the filling of Cell
        /// @param fill pointer to squad
        void set_filling(squad::Squad *fill);

        /// @brief  setter of the coordinates of Cell
        /// @param coor_new    point contains coordinates of Cell
        void set_coor(const point &coor_new);

        /// @brief  operator of equal compare of two cells
        /// @param other_cell   Cell to compare
        /// @return if two points are equal or not
        bool operator==(const Cell &other_cell) const;

        /// @brief  operator of assignment
        /// @param cell cell to assign
        /// @return new state if class object (this)
        Cell operator=(Cell cell);
    };
}

#endif