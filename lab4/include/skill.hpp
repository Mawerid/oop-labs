#ifndef SKILL_HPP
#define SKILL_HPP

#include <vector>
#include "squad.hpp"
#include "constants.hpp"

namespace school
{
    class skill
    {
    private:
        constant::unit name;
        squad::squad desc;
        unsigned min_study;
        unsigned energy;
        double count_coef;
        std::vector<constant::unit> easy_kill;
        std::vector<constant::unit> easy_die;

    public:
        skill();
        skill(const squad::squad &);
        skill(const constant::unit &);
        skill(const squad::squad &, const squad::squad &, const unsigned &);
        skill(const skill&);

        void set_name(const constant::unit &);
        void set_desc(const squad::squad &);
        void set_min_study(const unsigned &);
        void set_energy(const unsigned &);
        void set_count_coef(const unsigned &);
        void set_easy_kill(const std::vector<constant::unit> &);
        void set_easy_die(const std::vector<constant::unit> &);

        constant::unit get_name();
        squad::squad get_desc();
        unsigned get_min_study();
        unsigned get_energy();
        unsigned get_count_coef();
        std::vector<constant::unit> get_easy_kill();
        std::vector<constant::unit> get_easy_die();

        void add_easy_kill(const constant::unit &);
        void add_easy_die(const constant::unit &);

        void remove_easy_kill(const constant::unit &);
        void remove_easy_die(const constant::unit &);

        bool check_easy_kill(const constant::unit &);
        bool check_easy_die(const constant::unit &);
    };
}

#endif