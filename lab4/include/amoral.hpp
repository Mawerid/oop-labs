#ifndef AMORAL_HPP
#define AMORAL_HPP

#include "unit.hpp"

namespace squad
{
    enum class amoral_type
    {
        CENTRY,
        INFESTOR,
        GNOME,
        CYCLONE,
        TYPHON
    };

    /// @brief class of amoral unit type
    class Amoral : public Unit
    {
    protected:
        amoral_type type;

    public:
        /// @brief  empty constructor
        Amoral();

        /// @brief  constructor
        /// @param new_type type of amoral unit
        Amoral(const amoral_type &new_type);

        /// @brief   constructor
        /// @param new_type type of amoral unit
        /// @param dmg  amount of damage
        /// @param def  amoubt of defense
        Amoral(const amoral_type &new_type, const unsigned &dmg, const unsigned &def);

        ~Amoral();

        /// @brief  getter of type
        /// @return type of amoral unit
        amoral_type get_type() const;

        /// @brief  setter of type
        /// @param new_type new type of amoral unit
        void set_type(const amoral_type &new_type);

        /// @brief  getter of damage
        /// @return damage
        unsigned get_damage_val() const;

        /// @brief  getter of defense
        /// @return defense
        unsigned get_defense_val() const;

        /// @brief  setter of damage
        /// @param dam  damage
        void set_damage_val(const unsigned &dam);

        /// @brief  setter of defense
        /// @param def  defense
        void set_defense_val(const unsigned &def);

        /// @brief  hit other squad
        /// @param squad    squad to hit
        void hit(Squad *squad);

        /// @brief  get damage from other squad
        /// @param squad    squad get hit from
        void defence(Squad *squad);
    };
}

#endif