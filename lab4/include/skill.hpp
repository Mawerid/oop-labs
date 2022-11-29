#ifndef SKILL_HPP
#define SKILL_HPP

#include <vector>
#include "squad.hpp"
#include "constants.hpp"

namespace school
{
    /// @brief
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
        /// @brief
        Skill();

        /// @brief 
        /// @param new_decs 
        Skill(const squad::Squad &new_decs);

        /// @brief 
        /// @param new_name 
        Skill(const constant::unit &new_name);


        /// @brief 
        /// @param new_name 
        /// @param new_decs 
        /// @param study 
        /// @param nrgy 
        /// @param coef 
        Skill(const constant::unit &new_name, const squad::Squad &new_decs, const unsigned &study, const unsigned &nrgy, const double &coef);

        /// @brief 
        /// @param skill 
        Skill(const Skill &skill);

        /// @brief 
        /// @param new_name 
        void set_name(const constant::unit &new_name);

        /// @brief 
        /// @param new_decs 
        void set_desc(const squad::Squad &new_decs);

        /// @brief 
        /// @param new_study 
        void set_min_study(const unsigned &new_study);

        /// @brief 
        /// @param nrgy 
        void set_energy(const unsigned &nrgy);

        /// @brief 
        /// @param new_coef 
        void set_count_coef(const unsigned &new_coef);

        /// @brief 
        /// @param new_list 
        void set_easy_kill(const std::vector<constant::unit> &new_list);


        /// @brief 
        /// @return 
        constant::unit get_name() const;

        /// @brief 
        /// @return 
        squad::Squad get_desc() const;

        /// @brief 
        /// @return 
        unsigned get_min_study() const;

        /// @brief 
        /// @return 
        unsigned get_energy() const;

        /// @brief 
        /// @return 
        unsigned get_count_coef() const;

        /// @brief 
        /// @return 
        std::vector<constant::unit> get_easy_kill() const;

        /// @brief 
        /// @param new_name 
        void add_easy_kill(const constant::unit &new_name);

        /// @brief 
        /// @param new_name 
        void remove_easy_kill(const constant::unit &new_name);

        /// @brief 
        /// @param new_name 
        /// @return 
        bool check_easy_kill(const constant::unit &new_name);
    };
}

#endif