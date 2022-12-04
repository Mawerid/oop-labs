#include "../include/immortal.hpp"

namespace squad
{
    Immortal::Immortal()
    {
        restore = 1;
        probability = 1.0;
    }

    Immortal::Immortal(const unsigned &restore_val)
    {
        restore = restore_val;
        probability = 1.0;
    }

    Immortal::Immortal(const double &prob_val)
    {
        restore = 1;
        probability = prob_val;
    }

    Immortal::Immortal(const unsigned &restore_val, const double &prob_val)
    {
        restore = restore_val;
        probability = prob_val;
    }

    unsigned Immortal::get_restore() { return restore; }

    double Immortal::get_probability() { return probability; }

    void Immortal::set_restore(const unsigned &restore_val) { restore = restore_val; }

    void Immortal::set_probability(const double &prob_val) { probability = prob_val; }

    void Immortal::heal()
    {
    }
}