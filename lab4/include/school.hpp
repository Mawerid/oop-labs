#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <vector>

#include "skill.hpp"

namespace school {
/// @brief  class of schools in game
class School {
   private:
    constant::school_type type_;
    std::vector<Skill> skill_list_;

   public:
    using list = std::vector<Skill>;

    /// @brief  constructor
    /// @param type type of school(name)
    School(const constant::school_type &type);

    /// @brief  constructor
    /// @param type type of school(name)
    /// @param skill_list   vector of skills of this school
    School(const constant::school_type &type, const list &skill_list);

    /// @brief  copy constructor
    /// @param school   school to copy
    School(const School &school) = default;

    /// @brief  move constructor
    /// @param school    school to move
    School(School &&school) = default;

    ~School() = default;

    /// @brief  setter of new type
    /// @param type new type of school
    void set_type(const constant::school_type &type);

    /// @brief  setter of skill vector
    /// @param skill_list   new skill vector
    void set_skill_list(const list &skill_list);

    /// @brief  add func to current skill vector
    /// @param skill    skill to add
    void add_skill(const Skill &skill);

    /// @brief  delete skill form skill list
    /// @param name name of skill to delete
    void remove_skill(const Skill &skill);

    /// @brief  check for skill in skill list
    /// @param name name of skill ot check
    /// @return is skill's name in list or not
    bool check_skill(const constant::unit &skill_name);

    /// @brief getter of skill from skill list
    /// @param skill_name name of skill
    /// @return skill from school
    Skill get_skill(const constant::unit &skill_name);

    /// @brief  getter of school's type
    /// @return school's type
    constant::school_type get_type() const;

    /// @brief  getter of vector of skills
    /// @return skills vector
    list get_skill_list() const;

    /// @brief  copy operator of assignment
    /// @param school    squad to assign
    /// @return new state of class object (this)
    School &operator=(const School &school) = default;

    /// @brief  move operator of assignment
    /// @param school    squad to assign
    /// @return new state of class object (this)
    School &operator=(School &&school) = default;

    /// @brief  operator of equality
    /// @param school school to check
    /// @return is they equal or not
    bool operator==(const School &school) const;

    /// @brief  operator !=
    /// @param school school to check
    /// @return is they eqial or not
    bool operator!=(const School &school) const;

    /// @brief  operator <
    /// @param school school to check
    /// @return is less or not
    bool operator<(const School &school) const;

    /// @brief  operator >
    /// @param school school to check
    /// @return is greater or not
    bool operator>(const School &school) const;

    /// @brief  operator <=
    /// @param school school to check
    /// @return is less or not
    bool operator<=(const School &school) const;

    /// @brief  operator >=
    /// @param school school to check
    /// @return is greater or not
    bool operator>=(const School &school) const;
};
}  // namespace school

#endif