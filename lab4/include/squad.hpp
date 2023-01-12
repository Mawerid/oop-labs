#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "constants.hpp"

namespace squad {
/// @brief parent class of all objects in game
class Squad {
   protected:
    unsigned motivation_;
    unsigned health_;
    unsigned max_health_;
    size_t quantity_;
    unsigned speed_;
    unsigned experience_;
    unsigned team_;
    constant::unit name_;

   public:
    /// @brief  constructor
    /// @param name squad name
    explicit Squad(const constant::unit &name);

    /// @brief  constructor
    /// @param name squad name
    /// @param team squad team
    Squad(const constant::unit &name, const unsigned &team);

    /// @brief  constructor
    /// @param motivation    motivation
    /// @param health health
    /// @param max_health max health
    /// @param quantity    quantity
    /// @param speed  speed
    /// @param experience  experience
    /// @param team squad team
    /// @param name squad name
    Squad(const unsigned &motivation, const unsigned &health,
          const unsigned &max_health, const size_t quantity,
          const unsigned &speed, const unsigned &experience,
          const unsigned &team, const constant::unit &name);

    /// @brief  copy constructor
    /// @param squad    squad to copy
    Squad(const Squad &squad);

    /// @brief  move constructor
    /// @param squad    squad to move
    Squad(Squad &&squad);

    ~Squad();

    /// @brief  setter of motivation
    /// @param motivation    motivation
    void set_motivation(const unsigned &motivation);

    /// @brief  setter of current health
    /// @param health health
    void set_health(const unsigned &health);

    /// @brief  setter of maximum health
    /// @param max_health max health
    void set_max_health(const unsigned &max_health);

    /// @brief  setter of speed
    /// @param speed  speed
    void set_speed(const unsigned &speed);

    /// @brief  setter of experience
    /// @param experience  experience
    void set_experience(const unsigned &experience);

    /// @brief  setter of squad's team
    /// @param team squad team
    void set_team(const unsigned &team);

    /// @brief  setter of quantity
    /// @param quantity    quantity
    void set_quantity(const size_t &quantity);

    /// @brief  setter of squad's name
    /// @param name squad name
    void set_name(const constant::unit &name);

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