#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <list>
#include "skill.hpp"
#include "constants.hpp"

namespace school
{

    class school
    {
    private:
        constant::school_type type;
        std::list<skill> skill_list;

    public:
        school(const constant::school_type &);
        school(const constant::school_type &, const skill &);
        school(const constant::school_type &, const std::list<skill> &);
        school(const school &);

        void set_type(const constant::school_type &);
        void set_skill_list(const std::list<skill> &);

        void add_skill(const skill &);

        constant::school_type get_type();
        std::list<skill> get_skill_list();
    };
}

#endif