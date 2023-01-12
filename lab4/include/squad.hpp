#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "constants.hpp"

namespace squad {
/// @brief parent class of all objects in game
class Squad {
   protected:
    unsigned motivation;
    unsigned health;
    unsigned max_health;
    size_t quantity;
    unsigned speed;
    unsigned experience;
    unsigned team;
    constant::unit name;

   public:
    /// @brief  constructor
    /// @param new_name squad name
    explicit Squad(const constant::unit &new_name);

    /// @brief  constructor
    /// @param new_name squad name
    /// @param new_team squad team
    Squad(const constant::unit &new_name, const unsigned &new_team);

    /// @brief  constructor
    /// @param motiv    motivation
    /// @param heal health
    /// @param max_heal max health
    /// @param quant    quantity
    /// @param spd  speed
    /// @param exp  experience
    /// @param new_team squad team
    /// @param new_name squad name
    Squad(const unsigned &motiv, const unsigned &heal,
          const unsigned &max_heal, const size_t quant,
          const unsigned &spd, const unsigned &exp,
          const unsigned &new_team, const constant::unit &new_name);

    /// @brief  copy constructor
    /// @param squad    squad to copy
    Squad(const Squad &squad);

    /// @brief  move constructor
    /// @param squad    squad to move
    Squad(Squad &&squad);

    ~Squad();

    /// @brief  setter of motivation
    /// @param motiv    motivation
    void set_motivation(const unsigned &motiv);

    /// @brief  setter of current health
    /// @param heal health
    void set_health(const unsigned &heal);

    /// @brief  setter of maximum health
    /// @param max_heal max health
    void set_max_health(const unsigned &max_heal);

    /// @brief  setter of speed
    /// @param spd  speed
    void set_speed(const unsigned &spd);

    /// @brief  setter of experience
    /// @param exp  experience
    void set_experience(const unsigned &exp);

    /// @brief  setter of squad's team
    /// @param new_team squad team
    void set_team(const unsigned &new_team);

    /// @brief  setter of quantity
    /// @param quant    quantity
    void set_quantity(const size_t &quant);

    /// @brief  setter of squad's name
    /// @param new_name squad name
    void set_name(const constant::unit &new_name);

    /// @brief  getter of motivation
    /// @return motivation
    unsigned get_motivation() const;

    /// @brief  getter of current health
    /// @return health
    unsigned get_health() const;

    /// @brief  getter of maximum health
    /// @return max health
    unsigned get_max_health() const;

    /// @brief  getter of speed
    /// @return speed
    unsigned get_speed() const;

    /// @brief  getter of experience
    /// @return experience
    unsigned get_experience() const;

    /// @brief  getter of squad's team
    /// @return squad team
    unsigned get_team() const;

    /// @brief  getter of quantity
    /// @return quantity
    size_t get_quantity() const;

    /// @brief  getter of squad's name
    /// @return squad name
    constant::unit get_name() const;

    /// @brief  getting damage from other units
    /// @param damage   damage
    void get_damage(const unsigned &damage);

    /// @brief  copy operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Squad &operator=(const Squad &squad);

    /// @brief  move operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Squad &operator=(Squad &&squad);

    /// @brief  operator of equality
    /// @param squad squad to check
    /// @return is they equal or not
    bool operator==(const Squad &squad);

    /// @brief  operator !=
    /// @param squad squad to check
    /// @return is they eqial or not
    bool operator!=(const Squad &squad);
};
}  // namespace squad

#endif