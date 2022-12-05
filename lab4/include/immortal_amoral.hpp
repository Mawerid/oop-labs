#ifndef IMMORTAL_AMORAL_HPP
#define IMMORTAL_AMORAL_HPP

#include "amoral.hpp"
#include "immortal.hpp"

namespace squad
{
    enum class immortal_amoral_type
    {
        COLOSSUS,
        DISRUPTOR,
    };

    /// @brief  class of immortal amoral unit type
    class Immortal_amoral : public Amoral, public Immortal
    {
    protected:
        immortal_amoral_type type;

    public:
        /// @brief  empty constructor
        Immortal_amoral();

        /// @brief  constructor
        /// @param new_type type of immortal amoral unit
        Immortal_amoral(const immortal_amoral_type &new_type);

        ~Immortal_amoral();

        /// @brief  getter of unit type
        /// @return immortal amoral unit type
        immortal_amoral_type get_type();

        /// @brief  setter of unit type
        /// @param new_type new type of immortal amoral unit
        void set_type(const immortal_amoral_type &new_type);

        /// @brief  getter of restoration value
        /// @return restoration value
        unsigned get_restore();

        /// @brief  getter of probability value
        /// @return probability value
        double get_probability();

        /// @brief  setter of restoration value
        /// @param restore_val  new amount of creatures, that can be restored
        void set_restore(const unsigned &restore_val);

        /// @brief  setter of probability value
        /// @param prob_val new probability value
        void set_probability(const double &prob_val);

        /// @brief  func, that can restore some creatures in squad
        void heal();
    };
}

#endif