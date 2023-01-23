#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <map>
#include <queue>
#include <string>
#include <vector>

#include "cell.hpp"

namespace game {
enum player_type {
    RIGHT,
    LEFT
};

/// @brief class of all game
class Landscape {
   public:
    typedef std::vector<std::vector<field::Cell>> map_type;
    typedef std::queue<squad::Squad *> queue;
    typedef std::pair<size_t, size_t> size_type;

   private:
    map_type map_;
    queue units_list_;

   public:
    const size_type size_ = {MAP_SIZE_VERTICAL, MAP_SIZE_HORIZONTAL};

    /// @brief  empty constructor
    Landscape();

    /// @brief  cosntructor
    /// @param map map of game
    Landscape(const map_type &map);

    /// @brief constructor
    /// @param map map of game
    /// @param units_list queue with units exists
    Landscape(const map_type &map, const queue &units_list);

    /// @brief  copy constructor
    /// @param game    game to copy
    Landscape(const Landscape &game);

    /// @brief  move constructor
    /// @param game    game to move
    Landscape(Landscape &&game);

    ~Landscape();

    /// @brief free pointer to squad
    /// @param squad squad to free
    void free_squad(squad::Squad *squad);

    /// @brief  setter of map
    /// @param map root of 2D tree
    void set_map(const map_type &map);

    /// @brief  setter of units list
    /// @param units_list new units list
    void set_units_list(const queue &units_list);

    /// @brief  getter of map
    /// @return map
    map_type &get_map();

    /// @brief  getter of units list
    /// @return units list
    queue &get_units_list();

    /// @brief  move squad from one cell to another
    /// @param cell_from   cell from
    /// @param cell_to   cell to
    void move_squad(field::Cell &cell_from, field::Cell &cell_to);

    /// @brief  set squad to cell
    /// @param cell cell to set
    /// @param squad    squad to set
    void set_squad(field::Cell &cell, squad::Squad *squad);

    /// @brief function of play
    /// @param command type of command
    /// @param args arguments for command
    void play_next(char command, std::vector<unsigned> args);

    /// @brief getter of next squad in queue
    /// @return next squad to play
    squad::Squad *get_next();

    /// @brief generate map with some obstacles
    /// @param obstacles_count count of obstacles
    /// @return generated map
    map_type generate_map(const size_t &obstacles_count);

    /// @brief save game to file
    void save_game() const;

    /// @brief load game from file
    void load_game();

    /// @brief  copy operator of assignment
    /// @param game    game to assign
    /// @return new state of class object (this)
    Landscape &operator=(const Landscape &game);

    /// @brief  move operator of assignment
    /// @param game    game to assign
    /// @return new state of class object (this)
    Landscape &operator=(Landscape &&game);

    /// @brief  operator of equality
    /// @param game game to check
    /// @return is they equal or not
    bool operator==(const Landscape &game) const;

    /// @brief  operator !=
    /// @param game game to check
    /// @return is they eqial or not
    bool operator!=(const Landscape &game) const;
};
}  // namespace game

#endif