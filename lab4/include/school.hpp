#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <vector>
#include "skill.hpp"
#include "constants.hpp"

namespace school
{
    /// @brief  class of schools in game
    class School
    {
    private:
        constant::school_type type;
        std::vector<Skill> skill_list;

    public:
        /// @brief  constructor
        /// @param new_type type of school(name)
        School(const constant::school_type &new_type);

        /// @brief  constructor
        /// @param new_type type of school(name)
        /// @param new_skill    skiil of this school
        School(const constant::school_type &new_type, const Skill &new_skill);

        /// @brief  constructor
        /// @param new_type type of school(name)
        /// @param new_skill_list   vector of skills of this school
        School(const constant::school_type &new_type, const std::vector<Skill> &new_skill_list);

        /// @brief  copy constructor
        /// @param school   school to copy
        School(const School &school);

        /// @brief  setter of new type
        /// @param new_type new type of school
        void set_type(const constant::school_type &new_type);

        /// @brief  setter of skill vector
        /// @param new_skill_list   new skill vector
        void set_skill_list(const std::vector<Skill> &new_skill_list);

        /// @brief  add func to current skill vector
        /// @param new_skill    skill to add
        void add_skill(const Skill &new_skill);

        /// @brief  getter of school's type
        /// @return school's type
        constant::school_type get_type() const;

        /// @brief  getter of vector of skills
        /// @return skills vector
        std::vector<Skill> get_skill_list() const;

        /// @brief 
        /// @param school 
        /// @return 
        std::strong_ordering operator<=>(const School &school) const;
    };
}

#endif