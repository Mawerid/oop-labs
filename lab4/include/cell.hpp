#ifndef CELL_HPP
#define CELL_HPP

#include "lord.hpp"

namespace field {
/// @brief  3 types of Cell in field
enum class cell_type {
    FREE,
    BUSY,
    OBSTAClE
};

/// @brief  class describing common Point
class Point {
   private:
    int x_ = 0;
    int y_ = 0;

   public:
    /// @brief  empty constructor
    Point();

    /// @brief  constuctor
    /// @param x    x coordinate of Point
    /// @param y    y coordinate of Point
    Point(const int &x, const int &y);

    /// @brief  copy constructor
    /// @param point  other point
    Point(const Point &point) = default;

    /// @brief  move constructor
    /// @param point  other point
    Point(Point &&point) = default;

    ~Point() = default;

    /// @brief  setter of x coordinate
    /// @param x    new x coordinate of point
    void set_x(const int &x);

    /// @brief  setter of y coordinate
    /// @param y    new y coordinate of point
    void set_y(const int &y);

    /// @brief  getter of x coordinate
    /// @return x coordinate
    int get_x() const;

    /// @brief  getter of y coordinate
    /// @return y coordinate
    int get_y() const;

    /// @brief  calculate distance between two points
    /// @param point  second point
    /// @return distance between two points
    double distance(const Point &point) const;

    /// @brief function to understand is this point in raduius of other
    /// @param radius radius to check
    /// @param point  second point
    /// @return is it near or not
    bool near(const unsigned &radius, const Point &point) const;

    /// @brief  copy operator of assignment
    /// @param point    point to assign
    /// @return new state of class object (this)
    Point &operator=(const Point &point) = default;

    /// @brief  move operator of assignment
    /// @param point    point to assign
    /// @return new state of class object (this)
    Point &operator=(Point &&point) = default;

    /// @brief  operator of equality
    /// @param point point to check
    /// @return is they equal or not
    bool operator==(const Point &point) const;

    /// @brief  operator !=
    /// @param point point to check
    /// @return is they eqial or not
    bool operator!=(const Point &point) const;

    /// @brief  operator >
    /// @param point point to check
    /// @return is they eqial or not
    bool operator>(const Point &point) const;

    /// @brief  operator <
    /// @param point point to check
    /// @return is they eqial or not
    bool operator<(const Point &point) const;

    /// @brief  operator <=
    /// @param point point to check
    /// @return is they eqial or not
    bool operator<=(const Point &point) const;

    /// @brief  operator >=
    /// @param point point to check
    /// @return is they eqial or not
    bool operator>=(const Point &point) const;
};

/// @brief class describing a Cell in the game field
class Cell {
   private:
    cell_type type_;
    Point coordinates_;
    squad::Squad *squad_ = nullptr;

   public:
    /// @brief  constructor
    /// @param coordinates    coordinates of Cell in field
    /// @param type type of Cell
    /// @param squad filling of the Cell
    Cell(const Point &coordinates, const cell_type &type,
         squad::Squad *squad = nullptr);

    /// @brief constructor
    /// @param x x coordinate of cell
    /// @param y y coordinate of cell
    /// @param type type of Cell
    /// @param squad filling of the Cell
    Cell(const int &x, const int &y, const cell_type &type,
         squad::Squad *squad = nullptr);

    /// @brief  copy constructor
    /// @param cell Cell to copy
    Cell(const Cell &cell);

    /// @brief  move constructor
    /// @param cell Cell to move
    Cell(Cell &&cell);

    ~Cell();

    /// @brief  getter of the type
    /// @return type of Cell
    cell_type get_type() const;

    /// @brief  getter of the squad
    /// @return pointer to squad of Cell
    squad::Squad *get_squad() const;

    /// @brief  getter of the coordinates of Cell
    /// @return point contains coordinates of Cell
    Point get_coordinates() const;

    /// @brief  setter of the Cell type
    /// @param type new type of Cell
    void set_type(const cell_type &type);

    /// @brief  setter of the squad of Cell
    /// @param squad Pointer to squad
    void set_squad(squad::Squad *squad);

    /// @brief  setter of the coordinates of Cell
    /// @param coordinates    Point contains coordinates of Cell
    void set_coordinates(const Point &coordinates);

    /// @brief free squad pointer;
    void free_squad();

    /// @brief  calculate distance between two cells
    /// @param cell  second Cell
    /// @return distance between two cells
    double distance(const Cell &cell) const;

    /// @brief function to understand is this cell in raduius of other
    /// @param radius radius to check
    /// @param cell  second cell
    /// @return is it near or not
    bool near(const unsigned &radius, const Cell &cell) const;

    /// @brief  copy operator of assignment
    /// @param cell    cell to assign
    /// @return new state of class object (this)
    Cell &operator=(const Cell &cell);

    /// @brief  move operator of assignment
    /// @param cell    cell to assign
    /// @return new state of class object (this)
    Cell &operator=(Cell &&cell);

    /// @brief  operator of equality
    /// @param cell cell to check
    /// @return is they equal or not
    bool operator==(const Cell &cell) const;

    /// @brief  operator !=
    /// @param cell cell to check
    /// @return is they eqial or not
    bool operator!=(const Cell &cell) const;

    /// @brief  operator >
    /// @param cell cell to check
    /// @return is they eqial or not
    bool operator>(const Cell &cell) const;

    /// @brief  operator <
    /// @param cell cell to check
    /// @return is they eqial or not
    bool operator<(const Cell &cell) const;

    /// @brief  operator <=
    /// @param cell cell to check
    /// @return is they eqial or not
    bool operator<=(const Cell &cell) const;

    /// @brief  operator >=
    /// @param cell cell to check
    /// @return is they eqial or not
    bool operator>=(const Cell &cell) const;
};
}  // namespace field

#endif