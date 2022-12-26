#ifndef LORD_HPP
#define LORD_HPP

#include <map>
#include <string>
#include "school.hpp"

namespace squad
{
    /// @brief class describes lord-player
    class Lord : public Squad
    {
    private:
        std::string lord_name;
        unsigned energy;
        unsigned max_energy;
        double accum_coef;
        std::map<school::School, unsigned> knowledge;

    public:
        /// @brief  constructor
        /// @param name player name
        Lord(std::string &name);

        /// @brief  constructor
        /// @param name player name
        /// @param max_nrgy max energy
        Lord(std::string &name, const unsigned &max_nrgy);

        /// @brief  constructor
        /// @param name player name
        /// @param nrgy energy
        /// @param max_nrgy max energy
        Lord(std::string &name, const unsigned &nrgy, const unsigned &max_nrgy);

        /// @brief  getter of player's name
        /// @return name
        std::string get_name();

        /// @brief  getter of current energy
        /// @return current energy
        unsigned get_energy();

        /// @brief  getter of max energy
        /// @return max energy
        unsigned get_max_energy();

        /// @brief  getter of accumulation coefficient
        /// @return accumulation coefficient
        double get_accum_coef();

        /// @brief  getter of knowledge table
        /// @return knowledge table
        std::map<school::School, unsigned> get_knowledge();

        /// @brief  setter of player's name
        /// @param name name
        void set_name(const std::string &name);

        /// @brief  setter of current energy
        /// @param nrgy energy
        void set_energy(const unsigned &nrgy);

        /// @brief  setter of maximum energy
        /// @param max_nrgy max energy
        void set_max_energy(const unsigned &max_nrgy);

        /// @brief  setter of accumulation coefficient
        /// @param coef accumulation coefficient
        void set_accum_coef(const double &coef);

        /// @brief  setter of knowledge table
        /// @param new_knowledge    knowledge table
        void set_knowledge(const std::map<school::School, unsigned> &new_knowledge);

        /// @brief  upgrade some school level
        /// @param school_t   school to upgrade
        void upgrade_school(const constant::school_type &school_t);

        /// @brief  call new squad to field
        /// @param squad_name   squad name to call
        /// @return new squad pointer
        Squad *call_squad(const constant::unit &squad_name);
    };
}

#endif