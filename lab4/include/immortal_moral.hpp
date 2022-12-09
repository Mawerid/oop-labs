#ifndef IMMORTAL_MORAL_HPP
#define IMMORTAL_MORAL_HPP

#include "moral.hpp"
#include "immortal.hpp"

namespace squad
{
    enum class immortal_moral_type
    {
        DENDRIOD,
        REAPER,
        MIMIC
    };

    /// @brief  class of immortal moral unit type
    class Immortal_moral : public Moral, public Immortal
    {
    protected:
        immortal_moral_type type;

    public:
        /// @brief  empty constructor
        Immortal_moral();

        /// @brief  constructor
        /// @param new_type type of immortal moral unit
        Immortal_moral(const immortal_moral_type &new_type);
        
        ~Immortal_moral();

        /// @brief  getter of unit type
        /// @return immortal amoral unit type 
        immortal_moral_type get_type();

        /// @brief  setter of unit type
        /// @param new_type new type of immortal amoral unit 
        void set_type(const immortal_moral_type &new_type);

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