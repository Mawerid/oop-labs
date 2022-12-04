#ifndef IMMORTAL_HPP
#define IMMORTAL_HPP

namespace squad
{
    /// @brief  class of immortal unit type
    class Immortal
    {
    private:
        unsigned restore;
        double probability;

    public:
        /// @brief empty constructor
        Immortal();

        /// @brief  constructor
        /// @param restore_val  value of creatures, that can be restored
        Immortal(const unsigned &restore_val);

        /// @brief  constructor
        /// @param prob_val probability of restoring creatures
        Immortal(const double &prob_val);

        /// @brief  constructor
        /// @param restore_val  value of creatures, that can be restored
        /// @param prob_val probability of restoring creatures
        Immortal(const unsigned &restore_val, const double &prob_val);

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