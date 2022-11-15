#ifndef IMMORTAL_HPP
#define IMMORTAL_HPP

namespace squad
{
    class immortal
    {
    private:
        unsigned restore;
        double probability;

    public:
        immortal();
        immortal(const unsigned &);
        immortal(const double &);
        immortal(const unsigned &, const double &);

        unsigned get_restore();
        double get_probability();

        void set_restore(const unsigned &);
        void set_probability(const double &);

        void heal();
    };
}

#endif