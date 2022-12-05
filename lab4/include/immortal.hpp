#ifndef IMMORTAL_HPP
#define IMMORTAL_HPP

#include <cstdlib>
#include <ctime>

namespace squad
{
    /// @brief  class of immortal unit type
    class Immortal
    {
    protected:
        unsigned restore;
        double probability;

    public:
        /// @brief  getter of restoration value
        /// @return restoration value
        virtual unsigned get_restore() = 0;

        /// @brief  getter of probability value
        /// @return probability value
        virtual double get_probability() = 0;

        /// @brief  setter of restoration value
        /// @param restore_val  new amount of creatures, that can be restored
        virtual void set_restore(const unsigned &restore_val) = 0;

        /// @brief  setter of probability value
        /// @param prob_val new probability value
        virtual void set_probability(const double &prob_val) = 0;

        /// @brief  func, that can restore some creatures in squad
        virtual void heal() = 0;
    };
}

#endif