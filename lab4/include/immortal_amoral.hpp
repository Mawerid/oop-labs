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
        MIMIC
    };

    /// @brief
    class Immortal_amoral : public Amoral, public Immortal
    {
    private:
        immortal_amoral_type type;

    public:
        /// @brief
        Immortal_amoral();

        /// @brief
        /// @param new_type
        Immortal_amoral(const immortal_amoral_type &new_type);

        /// @brief
        /// @return
        immortal_amoral_type get_type();

        /// @brief
        /// @param new_type
        void set_type(const immortal_amoral_type &new_type);
    };
}

#endif