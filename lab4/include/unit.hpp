#ifndef UNIT_HPP
#define UNIT_HPP

#include "squad.hpp"

namespace squad
{
    /// @brief
    class Unit : public Squad
    {
    protected:
        unsigned damage;
        unsigned defense;

    public:
        /// @brief  empty constructor
        Unit();

        /// @brief constructor
        /// @param damage   damage value
        /// @param defense  defense value
        Unit(const unsigned &damage, const unsigned &defense);

        /// @brief  getter of damage
        /// @return damage
        virtual unsigned get_damage_val() const;

        /// @brief  getter of defense
        /// @return defense
        virtual unsigned get_defense_val() const;

        /// @brief  setter of damage
        /// @param dam  damage
        virtual void set_damage_val(const unsigned &dam);

        /// @brief  setter of defense
        /// @param def  defense
        virtual void set_defense_val(const unsigned &def);

        /// @brief  hit other squad
        /// @param squad    squad to hit   
        virtual void hit(Squad *squad);

        /// @brief  get damage from other squad
        /// @param squad    squad get hit from
        virtual void defence(Squad *squad);
    };
}

#endif