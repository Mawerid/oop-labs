#ifndef MORAL_HPP
#define MORAL_HPP

#include "unit.hpp"

namespace squad
{
    enum class moral_type
    {
        ROBOMECH,
        GHOST,
        ELF,
        MARINE,
        POLTERGEIST
    };

    class Moral : public Unit
    {
    protected:
        moral_type type;
        int moral;

    public:
        /// @brief
        Moral();

        /// @brief
        /// @param new_type
        Moral(const moral_type &new_type);

        /// @brief
        /// @param new_type
        /// @param new_moral
        Moral(const moral_type &new_type, const int &new_moral);

        /// @brief
        /// @param new_type
        /// @param new_moral
        /// @param damage
        /// @param defense
        Moral(const moral_type &new_type, const int &new_moral, const unsigned &damage, const unsigned &defense);

        /// @brief
        /// @return
        moral_type get_type() const;

        /// @brief
        /// @return
        int get_moral_val() const;

        /// @brief
        /// @param new_type
        void set_type(const moral_type &new_type);

        /// @brief
        /// @param new_moral
        void set_moral_val(const int &new_moral);

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

        /// @brief
        void balance();

        /// @brief
        /// @param modif
        void mod_moral(const int &modif);
    };
}

#endif