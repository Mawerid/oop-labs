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

    /// @brief class of moral unit type
    class Moral : public Unit
    {
    protected:
        moral_type type;
        int moral;

    public:
        /// @brief  empty constructor
        Moral();

        /// @brief  constructor
        /// @param new_type type of moral unit
        Moral(const moral_type &new_type);

        /// @brief  constructor
        /// @param new_type
        /// @param new_moral
        Moral(const moral_type &new_type, const int &new_moral);

        /// @brief  constructor
        /// @param new_type type of moral unit
        /// @param new_moral    moral value
        /// @param dmg  amount of damage
        /// @param def  amoubt of defense
        Moral(const moral_type &new_type, const int &new_moral, const unsigned &dmg, const unsigned &def);

        ~Moral();

        /// @brief  getter of type
        /// @return type of moral unit
        moral_type get_type() const;

        /// @brief  getter of moral
        /// @return moral value
        int get_moral_val() const;

        /// @brief  setter of type
        /// @param new_type new type of amoral unit
        void set_type(const moral_type &new_type);

        /// @brief  setter of moral
        /// @param new_moral    new moral value
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

        /// @brief  func to balance moral near 0
        void balance();

        /// @brief  modificate moral
        /// @param modif    moral value to add
        void mod_moral(const int &modif);

        void die();
    };
}

#endif