#ifndef IMMORTAL_MORAL_HPP
#define IMMORTAL_MORAL_HPP

#include "moral.hpp"
#include "immortal.hpp"

namespace squad
{
    enum class immortal_moral_type
    {
        REAPER,
        MIMIC
    };

    /// @brief  class of immortal moral unit type
    class Immortal_moral : public Moral, public Immortal
    {
    private:
        immortal_moral_type type;

    public:
        /// @brief  empty constructor
        Immortal_moral();

        /// @brief  constructor
        /// @param new_type type of immortal moral unit
        Immortal_moral(const immortal_moral_type &new_type);

        /// @brief  getter of unit type
        /// @return immortal amoral unit type 
        immortal_moral_type get_type();

        /// @brief  setter of unit type
        /// @param new_type new type of immortal amoral unit 
        void set_type(const immortal_moral_type &new_type);
    };
}

#endif