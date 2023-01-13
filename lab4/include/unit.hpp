#ifndef UNIT_HPP
#define UNIT_HPP

#include "squad.hpp"

namespace squad {
/// @brief  class of all units (abstact class)
class Unit : public Squad {
   protected:
    unsigned damage_ = 0;
    unsigned shield_ = 0;

   public:
    /// @brief constructor for Unit class
    /// @param name name of unit
    Unit(const constant::unit &name);

    /// @brief constructor for Unit class
    /// @param name name of unit
    /// @param damage damage of unit
    /// @param shield shield count of unit
    Unit(const constant::unit &name, const unsigned &damage,
         const unsigned &shield);

    ~Unit() = default;

    /// @brief  getter of damage
    /// @return damage
    unsigned get_damage_val() const;

    /// @brief  getter of defense
    /// @return defense
    unsigned get_defense_val() const;

    /// @brief  setter of damage
    /// @param dam  damage
    void set_damage_val(const unsigned &damage);

    /// @brief  setter of defense
    /// @param def  defense
    void set_defense_val(const unsigned &shield);

    /// @brief  hit other squad
    /// @param squad    squad to hit
    virtual void attack(Squad &squad) const = 0;

    /// @brief  get damage from other squad
    /// @param squad    squad get hit from
    virtual void defence(Squad &squad) = 0;
};
}  // namespace squad

#endif