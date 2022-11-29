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

    /// @brief 
    class Immortal_moral : public Moral, public Immortal
    {
    private:
        immortal_moral_type type;

    public:
        /// @brief 
        Immortal_moral();

        /// @brief 
        /// @param new_type 
        Immortal_moral(const immortal_moral_type &new_type);

        /// @brief 
        /// @return 
        immortal_moral_type get_type();

        /// @brief 
        /// @param new_type 
        void set_type(const immortal_moral_type &new_type);
    };
}

#endif