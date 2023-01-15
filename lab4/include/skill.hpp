#ifndef SKILL_HPP
#define SKILL_HPP

#include <vector>

#include "immortal.hpp"

namespace school {
/// @brief  class of each skill in the game
class Skill {
   private:
    constant::unit name_;
    unsigned minimal_study_;
    unsigned energy_;
    double count_coefficient_;
    std::vector<constant::unit> easy_kill_ = {};

   public:
    using unit_list = std::vector<constant::unit>;

    /// @brief  constructor
    /// @param name name of unit
    /// @param minimal_study    study for use
    /// @param energy energy to call
    /// @param count_coefficient coefficient to encrease amount of creatures
    Skill(const constant::unit &name, const unsigned &minimal_study,
          const unsigned &energy, const double &count_coefficient);

    /// @brief constructor
    /// @param name  name of unit
    /// @param minimal_study study for use
    /// @param energy energy to call
    /// @param count_coefficient coefficient to encrease amount of creatures
    /// @param easy_kill vector with units with greater damage
    Skill(const constant::unit &name, const unsigned &minimal_study,
          const unsigned &energy, const double &count_coefficient,
          const unit_list easy_kill);

    /// @brief  copy constructor
    /// @param skill    skill to copy
    Skill(const Skill &skill) = default;

    /// @brief  move constructor
    /// @param skill    skill to move
    Skill(Skill &&skill) = default;

    ~Skill() = default;

    /// @brief  setter of name of unit
    /// @param name new name of unit
    void set_name(const constant::unit &name);

    /// @brief  setter of study
    /// @param minimal_study    new study
    void set_minimal_study(const unsigned &minimal_study);

    /// @brief  setter of energy to call
    /// @param energy new energy to call
    void set_energy(const unsigned &energy);

    /// @brief  setter of coefficient of increase
    /// @param count_coefficient new coefficient of increase
    void set_count_coefficient(const double &count_coefficient);

    /// @brief  setter of easy kill list
    /// @param list new easy to kill units list
    void set_easy_kill(const unit_list &list);

    /// @brief  getter of name of unit
    /// @return name of unit
    constant::unit get_name() const;

    /// @brief  getter of study
    /// @return new study
    unsigned get_minimal_study() const;

    /// @brief  getter of energy to call
    /// @return energy to call
    unsigned get_energy() const;

    /// @brief  getter of coefficient of increase
    /// @return coefficient of increase
    double get_count_coefficient() const;

    /// @brief  getter of easy kill list
    /// @return easy to kill units list
    unit_list get_easy_kill() const;

    /// @brief  add unit to easy kill list
    /// @param name name of unit to add
    void add_easy_kill(const constant::unit &name);

    /// @brief  delete unit form easy kill list
    /// @param name name of unit to delete
    void remove_easy_kill(const constant::unit &name);

    /// @brief  check for unit in easy kill list
    /// @param name name of unit ot check
    /// @return is unit's name in list or not
    bool check_easy_kill(const constant::unit &name);

    /// @brief  copy operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Skill &operator=(const Skill &skill) = default;

    /// @brief  move operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Skill &operator=(Skill &&skill) = default;

    /// @brief  operator of equality
    /// @param squad squad to check
    /// @return is they equal or not
    bool operator==(const Skill &skill) const;

    /// @brief  operator !=
    /// @param squad squad to check
    /// @return is they eqial or not
    bool operator!=(const Skill &skill) const;
};
}  // namespace school

#endif