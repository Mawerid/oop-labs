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
    private:
        immortal_amoral_type type;

    public:
        /// @brief  empty constructor
        Immortal_amoral();

        /// @brief  constructor
        /// @param new_type type of immortal amoral unit
        Immortal_amoral(const immortal_amoral_type &new_type);

        /// @brief  getter of unit type
        /// @return immortal amoral unit type
        immortal_amoral_type get_type();

        /// @brief  setter of unit type
        /// @param new_type new type of immortal amoral unit
        void set_type(const immortal_amoral_type &new_type);
    };
}

#endif