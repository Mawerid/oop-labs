#include "../include/lord.hpp"

namespace squad
{
    Lord::Lord(std::string &name)
    {
        lord_name = name;
        energy = 0;
        max_energy = 0;
        accum_coef = 1.0;
        // knowledge = {}
    }

    Lord::Lord(std::string &name, const unsigned &max_nrgy)
    {
        lord_name = name;
        energy = max_energy;
        max_energy = max_energy;
        accum_coef = 1.0;
        // knowledge = {}
    }

    Lord::Lord(std::string &name, const unsigned &nrgy, const unsigned &max_nrgy)
    {
        lord_name = name;
        energy = 0;
        max_energy = 0;
        accum_coef = 1.0;
        // knowledge = {}
    }

    std::string Lord::get_name() { return lord_name; }

    unsigned Lord::get_energy() { return energy; }

    unsigned Lord::get_max_energy() { return max_energy; }

    double Lord::get_accum_coef() { return accum_coef; }

    std::map<constant::school_type, unsigned> Lord::get_knowledge() { return knowledge; }

    void Lord::set_name(const std::string &name) { lord_name = name; }

    void Lord::set_energy(const unsigned &nrgy) { energy = nrgy; }

    void Lord::set_max_energy(const unsigned &max_nrgy) { max_energy = max_nrgy; }

    void Lord::set_accum_coef(const double &coef) { accum_coef = coef; }

    void Lord::set_knowledge(const std::map<constant::school_type, unsigned> &new_knowledge) { knowledge = new_knowledge; }

    void Lord::upgrade_school(const constant::school_type &school)
    {
    }

    Squad *Lord::call_squad(const constant::unit &squad_name)
    {
    }
}