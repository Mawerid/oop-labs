#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <list>
#include "skill.hpp"
#include "constants.hpp"

namespace school
{
    /// @brief
    class School
    {
    private:
        constant::school_type type;
        std::list<Skill> skill_list;

    public:
        /// @brief 
        /// @param new_type 
        School(const constant::school_type &new_type);

        /// @brief 
        /// @param new_type 
        /// @param new_skill 
        School(const constant::school_type &new_type, const Skill &new_skill);

        /// @brief 
        /// @param new_type 
        /// @param new_skill_list 
        School(const constant::school_type &new_type, const std::list<Skill> &new_skill_list);

        /// @brief 
        /// @param school 
        School(const School &school);

        /// @brief 
        /// @param new_type 
        void set_type(const constant::school_type &new_type);

        /// @brief 
        /// @param new_skill_list 
        void set_skill_list(const std::list<Skill> &new_skill_list);

        /// @brief 
        /// @param new_skill 
        void add_skill(const Skill &new_skill);

        /// @brief 
        /// @return 
        constant::school_type get_type() const;

        /// @brief 
        /// @return 
        std::list<Skill> get_skill_list() const;
    };
}

#endif