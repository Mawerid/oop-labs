#include "../include/cell.hpp"

#include <math.h>

#include <stdexcept>

namespace field {
// Point

Point::Point() : x_(0), y_(0) {}

Point::Point(const int &x, const int &y) : x_(x), y_(y) {}

void Point::set_x(const int &x) { x_ = x; }

void Point::set_y(const int &y) { y_ = y; }

int Point::get_x() const { return x_; }

int Point::get_y() const { return y_; }

double Point::distance(const Point &point) const {
    return sqrt(pow((x_ - point.x_), 2) + pow((y_ - point.y_), 2));
}

bool Point::near(const unsigned &radius, const Point &point) const {
    if (distance(point) < static_cast<double>(radius))
        return true;
    else
        return false;
}

bool Point::operator==(const Point &point) const {
    if (x_ == point.x_ && y_ == point.y_)
        return true;
    else
        return false;
}

bool Point::operator!=(const Point &point) const {
    return !(*this == point);
}

bool Point::operator>(const Point &point) const {
    if (distance(Point(0, 0)) > point.distance(Point(0, 0)))
        return true;
    else
        return false;
}

bool Point::operator<(const Point &point) const {
    if (distance(Point(0, 0)) < point.distance(Point(0, 0)))
        return true;
    else
        return false;
}

bool Point::operator<=(const Point &point) const {
    return !(*this > point);
}

bool Point::operator>=(const Point &point) const {
    return !(*this < point);
}

/// Cell class

Cell::Cell(const Point &coordinates, const cell_type &type,
           squad::Squad *squad) : coordinates_(coordinates),
                                  type_(type),
                                  squad_(squad) {}

Cell::Cell(const int &x, const int &y, const cell_type &type,
           squad::Squad *squad) : coordinates_(Point(x, y)),
                                  type_(type),
                                  squad_(squad) {}

Cell::Cell(const Cell &cell) : type_(cell.type_),
                               coordinates_(cell.coordinates_) {
    squad_ = new squad::Squad(*cell.squad_);
}

Cell::Cell(Cell &&cell) : type_(cell.type_),
                          coordinates_(cell.coordinates_),
                          squad_(cell.squad_) {
    cell.squad_ = nullptr;
}

Cell::~Cell() {
    if (squad_ != nullptr)
        delete squad_;
}

cell_type Cell::get_type() const { return type_; }

squad::Squad *Cell::get_squad() const { return squad_; }

Point Cell::get_coordinates() const { return coordinates_; }

void Cell::set_type(const cell_type &type) { type_ = type; }

void Cell::set_squad(squad::Squad *squad) {
    if (type_ != cell_type::FREE)
        throw std::invalid_argument("Impossible movement of squad");
    squad_ = squad;
    type_ = cell_type::BUSY;
}

void Cell::free_squad() {
    squad_ = nullptr;
    type_ = cell_type::FREE;
}

void Cell::set_coordinates(const Point &coordinates) {
    coordinates_ = coordinates;
}

double Cell::distance(const Cell &cell) const {
    return coordinates_.distance(cell.coordinates_);
}

bool Cell::near(const unsigned &radius, const Cell &cell) const {
    return coordinates_.near(radius, cell.coordinates_);
}

Cell &Cell::operator=(const Cell &cell) {
    type_ = cell.type_;
    coordinates_ = cell.coordinates_;
    delete squad_;
    squad_ = cell.squad_;

    return *this;
}

Cell &Cell::operator=(Cell &&cell) {
    std::swap(type_, cell.type_);
    std::swap(coordinates_, cell.coordinates_);
    std::swap(squad_, cell.squad_);

    return *this;
}

bool Cell::operator==(const Cell &cell) const {
    if (type_ == cell.type_ && coordinates_ == cell.coordinates_ &&
        squad_ == cell.squad_)
        return true;
    else
        return false;
}

bool Cell::operator!=(const Cell &cell) const {
    return !(*this == cell);
}

bool Cell::operator>(const Cell &cell) const {
    return coordinates_ > cell.coordinates_;
}

bool Cell::operator<(const Cell &cell) const {
    return coordinates_ < cell.coordinates_;
}

bool Cell::operator<=(const Cell &cell) const {
    return coordinates_ <= cell.coordinates_;
}

bool Cell::operator>=(const Cell &cell) const {
    return coordinates_ >= cell.coordinates_;
}
}  // namespace field