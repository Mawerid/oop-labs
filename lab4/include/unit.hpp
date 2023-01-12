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
    /// @brief  getter of damage
    /// @return damage
    virtual unsigned get_damage_val() const = 0;

    /// @brief  getter of defense
    /// @return defense
    virtual unsigned get_defense_val() const = 0;

    /// @brief  setter of damage
    /// @param dam  damage
    virtual void set_damage_val(const unsigned &damage) = 0;

    /// @brief  setter of defense
    /// @param def  defense
    virtual void set_defense_val(const unsigned &shield) = 0;

    /// @brief  hit other squad
    /// @param squad    squad to hit
    virtual void hit(Squad &squad) = 0;

    /// @brief  get damage from other squad
    /// @param squad    squad get hit from
    virtual void defense(Squad &squad) = 0;
};
}  // namespace squad

#endif