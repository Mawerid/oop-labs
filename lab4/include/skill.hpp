#ifndef SKILL_HPP
#define SKILL_HPP

#include <vector>
#include "immortal.hpp"

namespace school
{
    /// @brief  class of each skill in the game
    class Skill
    {
    private:
        constant::unit name;
        squad::Squad desc;
        unsigned min_study;
        unsigned energy;
        double count_coef;
        std::vector<constant::unit> easy_kill;

    public:
        /// @brief  empty constructor
        Skill();

        /// @brief  constructor
        /// @param new_decs desciption of squad
        Skill(const squad::Squad &new_decs);

        /// @brief  constructor
        /// @param new_name name of unit
        Skill(const constant::unit &new_name);

        /// @brief  constructor
        /// @param new_name name of unit
        /// @param new_decs desciption of squad
        /// @param study    study for use
        /// @param nrgy energy to call
        /// @param coef coefficient to encrease amount of creatures in squad
        Skill(const constant::unit &new_name, const squad::Squad &new_decs, const unsigned &study, const unsigned &nrgy, const double &coef);

        /// @brief  copy constructor
        /// @param skill    skill to copy
        Skill(const Skill &skill);

        /// @brief  setter of name of unit
        /// @param new_name new name of unit
        void set_name(const constant::unit &new_name);

        /// @brief  setter of description of squad
        /// @param new_decs new description of squad
        void set_desc(const squad::Squad &new_decs);

        /// @brief  setter of study
        /// @param new_study    new study
        void set_min_study(const unsigned &new_study);

        /// @brief  setter of energy to call
        /// @param nrgy new energy to call
        void set_energy(const unsigned &nrgy);

        /// @brief  setter of coefficient of increase
        /// @param new_coef new coefficient of increase
        void set_count_coef(const double &new_coef);

        /// @brief  setter of easy kill list
        /// @param new_list new easy to kill units list
        void set_easy_kill(const std::vector<constant::unit> &new_list);

        /// @brief  getter of name of unit
        /// @return name of unit
        constant::unit get_name() const;

        /// @brief  getter of description of squad
        /// @return description of squad
        squad::Squad get_desc() const;

        /// @brief  getter of study
        /// @return new study
        unsigned get_min_study() const;

        /// @brief  getter of energy to call
        /// @return energy to call
        unsigned get_energy() const;

        /// @brief  getter of coefficient of increase
        /// @return coefficient of increase
        double get_count_coef() const;

        /// @brief  getter of easy kill list
        /// @return easy to kill units list
        std::vector<constant::unit> get_easy_kill() const;

        /// @brief  add unit to easy kill list
        /// @param new_name name of unit to add
        void add_easy_kill(const constant::unit &new_name);

        /// @brief  delete unit form easy kill list
        /// @param new_name name of unit to delete
        void remove_easy_kill(const constant::unit &new_name);

        /// @brief  check for unit in easy kill list
        /// @param new_name name of unit ot check
        /// @return is unit's name in listir not
        bool check_easy_kill(const constant::unit &new_name);
    };
}

#endif