#ifndef LORD_HPP
#define LORD_HPP

#include <map>
#include <string>
#include "squad.hpp"
#include "constants.hpp"

namespace squad
{
    class lord : public squad
    {
    private:
        std::string lord_name;
        unsigned energy;
        unsigned max_energy;
        double accum_coef;
        std::map<constant::school_type, unsigned> knowledge;
    public:
        lord();
        lord(std::string &);
        lord(std::string &, const unsigned &);
        lord(std::string &, const unsigned &, const unsigned &);

        std::string get_name();
        unsigned get_energy();
        unsigned get_max_energy();
        double get_accum_coef();
        std::map<constant::school_type, unsigned> get_knowledge();

        void set_name(const std::string &);
        void set_energy(const unsigned &);
        void set_max_energy(const unsigned &);
        void set_accum_coef(const double &);
        void set_knowledge(const std::map<constant::school_type, unsigned> &);

        void upgrade_school(const constant::school_type &);
        squad* call_squad(const constant::unit &);
    };
}

#endif