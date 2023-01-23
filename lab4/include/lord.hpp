#ifndef LORD_HPP
#define LORD_HPP

#include <map>
#include <string>

#include "school.hpp"

namespace squad {
/// @brief class describes lord-player
class Lord : public Squad {
   public:
    typedef std::map<school::School, unsigned> knowledge_type;

   private:
    std::string lord_name_;
    unsigned energy_ = START_ENERGY;
    unsigned max_energy_ = START_MAX_ENERGY;
    double accum_coefficient_ = 1.0;
    knowledge_type knowledge_;

   public:
    /// @brief constructor
    /// @param name player name
    /// @param team player team
    Lord(std::string &name, const unsigned &team);

    /// @brief copy constructor
    /// @param lord lord to copy
    Lord(const Lord &lord) = default;

    /// @brief move constructor
    /// @param lord lord to move
    Lord(Lord &&lord) = default;

    ~Lord() = default;

    /// @brief  getter of player's name
    /// @return name
    std::string get_lord_name() const;

    /// @brief  getter of current energy
    /// @return current energy
    unsigned get_energy() const;

    /// @brief  getter of max energy
    /// @return max energy
    unsigned get_max_energy() const;

    /// @brief  getter of accumulation coefficient
    /// @return accumulation coefficient
    double get_accum_coefficient() const;

    /// @brief  getter of knowledge table
    /// @return knowledge table
    knowledge_type get_knowledge() const;

    /// @brief  setter of player's name
    /// @param name name
    void set_lord_name(const std::string &name);

    /// @brief  setter of current energy
    /// @param energy energy
    void set_energy(const unsigned &energy);

    /// @brief  setter of maximum energy
    /// @param max_energy max energy
    void set_max_energy(const unsigned &max_energy);

    /// @brief  setter of accumulation coefficient
    /// @param accum_coefficien_ accumulation coefficient
    void set_accum_coefficient(const double &accum_coefficient);

    /// @brief  setter of knowledge table
    /// @param knowledge    knowledge table
    void set_knowledge(const knowledge_type &knowledge);

    /// @brief  upgrade some school level
    /// @param school   school to upgrade
    void upgrade_school(const constant::school_type &school);

    /// @brief  call new squad to field
    /// @param name   squad name to call
    /// @return new squad pointer
    Squad *call_squad(const constant::unit &name);

    /// @brief func to modify energy
    /// @param energy value to add to current energy
    void modify_energy(const int &energy);

    /// @brief func to modify experience
    /// @param experience value to add to current experience
    void modify_experience(const unsigned &experience);

    /// @brief  copy operator of assignment
    /// @param lord    lord to assign
    /// @return new state of class object (this)
    Lord &operator=(const Lord &lord) = default;

    /// @brief  move operator of assignment
    /// @param lord    lord to assign
    /// @return new state of class object (this)
    Lord &operator=(Lord &&lord) = default;

    /// @brief  operator of equality
    /// @param lord lord to check
    /// @return is they equal or not
    bool operator==(const Lord &lord) const;

    /// @brief  operator !=
    /// @param lord squad to check
    /// @return is they eqial or not
    bool operator!=(const Lord &lord) const;
};
}  // namespace squad

#endif