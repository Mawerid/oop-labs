#include "../include/immortal.hpp"

namespace squad
{
    /*Immortal::Immortal()
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
        if (prob_val >= 0.0 && prob_val <= 1.0)
            probability = prob_val;
        else
            probability = 1.0;
    }

    Immortal::Immortal(const unsigned &restore_val, const double &prob_val)
    {
        restore = restore_val;
        if (prob_val >= 0.0 && prob_val <= 1.0)
            probability = prob_val;
        else
            probability = 1.0;
    }

    Immortal::~Immortal()
    {
        
    }

    unsigned Immortal::get_restore() { return restore; }

    double Immortal::get_probability() { return probability; }

    void Immortal::set_restore(const unsigned &restore_val) { restore = restore_val; }

    void Immortal::set_probability(const double &prob_val)
    {
        if (prob_val >= 0.0 && prob_val <= 1.0)
            probability = prob_val;
    }*/

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

    Immortal_amoral::Immortal_amoral() { type = immortal_amoral_type::COLOSSUS; }

    Immortal_amoral::Immortal_amoral(const immortal_amoral_type &new_type) { type = new_type; }

    Immortal_amoral::~Immortal_amoral()
    {}

    immortal_amoral_type Immortal_amoral::get_type() { return type; }

    void Immortal_amoral::set_type(const immortal_amoral_type &new_type) { type = new_type; }

    void Immortal_amoral::heal()
    {
        std::srand(std::time(nullptr));
        double rand_check = (double)((std::rand() % 100) / 100);

        if (this->get_probability() > rand_check)
            this->set_health((this->get_health() + this->get_restore()));
    }

    unsigned Immortal_amoral::get_restore() { return restore; }

    double Immortal_amoral::get_probability() { return probability; }

    void Immortal_amoral::set_restore(const unsigned &restore_val) { restore = restore_val; }

    void Immortal_amoral::set_probability(const double &prob_val)
    {
        if (prob_val >= 0.0 && prob_val <= 1.0)
            probability = prob_val;
    }
}