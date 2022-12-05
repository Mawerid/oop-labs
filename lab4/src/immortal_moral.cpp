#include "../include/immortal_moral.hpp"

namespace squad
{
    Immortal_moral::Immortal_moral() { type = immortal_moral_type::REAPER; }

    Immortal_moral::Immortal_moral(const immortal_moral_type &new_type) { type = new_type; }

    Immortal_moral::~Immortal_moral()
    {}

    immortal_moral_type Immortal_moral::get_type() { return type; }

    void Immortal_moral::set_type(const immortal_moral_type &new_type) { type = new_type; }

    unsigned Immortal_moral::get_restore() { return restore; }

    double Immortal_moral::get_probability() { return probability; }

    void Immortal_moral::set_restore(const unsigned &restore_val) { restore = restore_val; }

    void Immortal_moral::set_probability(const double &prob_val)
    {
        if (prob_val >= 0.0 && prob_val <= 1.0)
            probability = prob_val;
    }

    void Immortal_moral::heal()
    {
        std::srand(std::time(nullptr));
        double rand_check = (double)((std::rand() % 100) / 100);

        if (this->get_probability() > rand_check)
            this->set_health((this->get_health() + this->get_restore()));
    }
}