#ifndef IMMORTAL_HPP
#define IMMORTAL_HPP

namespace squad
{
    /// @brief
    class Immortal
    {
    private:
        unsigned restore;
        double probability;

    public:
        /// @brief
        Immortal();

        /// @brief
        /// @param restore_val
        Immortal(const unsigned &restore_val);

        /// @brief
        /// @param prob_val
        Immortal(const double &prob_val);

        /// @brief
        /// @param restore_val
        /// @param prob_val
        Immortal(const unsigned &restore_val, const double &prob_val);

        /// @brief
        /// @return
        unsigned get_restore();

        /// @brief
        /// @return
        double get_probability();

        /// @brief
        /// @param restore_val
        void set_restore(const unsigned &restore_val);

        /// @brief
        /// @param prob_val
        void set_probability(const double &prob_val);

        /// @brief
        void heal();
    };
}

#endif