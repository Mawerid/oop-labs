#ifndef IMMORTAL_HPP
#define IMMORTAL_HPP

#include <cstdlib>
#include <ctime>

#include "common_units.hpp"

namespace squad {
/// @brief  class of immortal unit type
class Immortal {
   protected:
    unsigned restore_ = 10;
    double probability_ = 0.5;

   public:
    /// @brief empty constructor
    Immortal();

    /// @brief constructor
    /// @param restore restore value of health
    /// @param probability probability of restoration
    Immortal(const unsigned &restore, const double &probability);

    ~Immortal() = default;

    /// @brief  getter of restoration value
    /// @return restoration value
    unsigned get_restore() const;

    /// @brief  getter of probability value
    /// @return probability value
    double get_probability() const;

    /// @brief  setter of restoration value
    /// @param restore  new amount of creatures, that can be restored
    void set_restore(const unsigned &restore);

    /// @brief  setter of probability value
    /// @param probability new probability value
    void set_probability(const double &probability);

    /// @brief  func, that can restore some creatures in squad
    virtual void heal() = 0;
};

enum immortal_moral_type {
    DENDRIOD,
    REAPER,
    MIMIC
};

/// @brief  class of immortal moral unit type
class Immortal_moral : public Moral, public Immortal {
   protected:
    immortal_moral_type type_;

   public:
    /// @brief  convert immortal_moral_type to constant::unit
    /// @param type immortal moral type to convert
    /// @return equivalent unit type
    constant::unit convert_name(const immortal_moral_type &type) const;

    /// @brief  constructor
    /// @param type type of immortal moral unit
    Immortal_moral(const immortal_moral_type &type);

    /// @brief constructor
    /// @param type type of immortal moral unit
    /// @param damage amount of damage
    /// @param shield amount of defense
    /// @param moral moral value
    Immortal_moral(const immortal_moral_type &type, const unsigned &damage,
                   const unsigned &shield, const int &moral);

    /// @brief constructor
    /// @param type type of immortal moral unit
    /// @param damage amount of damage
    /// @param shield amount of defense
    /// @param restore restore value of health
    /// @param probability probability of restoration
    /// @param moral moral value
    Immortal_moral(const immortal_moral_type &type, const unsigned &damage,
                   const unsigned &shield, const unsigned &restore,
                   const double &probability, const int &moral);

    /// @brief  copy constructor
    /// @param squad    squad to copy
    Immortal_moral(const Immortal_moral &squad);

    /// @brief  move constructor
    /// @param squad    squad to move
    Immortal_moral(Immortal_moral &&squad);

    ~Immortal_moral() = default;

    /// @brief  getter of unit type
    /// @return immortal amoral unit type
    immortal_moral_type get_type() const;

    /// @brief  setter of unit type
    /// @param type new type of immortal amoral unit
    void set_type(const immortal_moral_type &type);

    /// @brief  func, that can restore some creatures in squad
    void heal() override;

    /// @brief  copy operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Immortal_moral &operator=(const Immortal_moral &squad) = default;

    /// @brief  move operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Immortal_moral &operator=(Immortal_moral &&squad) = default;

    /// @brief  operator of equality
    /// @param squad squad to check
    /// @return is they equal or not
    bool operator==(const Immortal_moral &squad);

    /// @brief  operator !=
    /// @param squad squad to check
    /// @return is they eqial or not
    bool operator!=(const Immortal_moral &squad);
};

enum immortal_amoral_type {
    COLOSSUS,
    DISRUPTOR,
};

/// @brief  class of immortal amoral unit type
class Immortal_amoral : public Amoral, public Immortal {
   protected:
    immortal_amoral_type type_;

   public:
    /// @brief  convert amoral_type to constant::unit
    /// @param type amoral type to convert
    /// @return equivalent unit type
    constant::unit convert_name(const immortal_amoral_type &type) const;

    /// @brief  constructor
    /// @param type type of immortal moral unit
    Immortal_amoral(const immortal_amoral_type &type);

    /// @brief constructor
    /// @param type type of immortal moral unit
    /// @param damage amount of damage
    /// @param shield amount of defense
    Immortal_amoral(const immortal_amoral_type &type, const unsigned &damage,
                    const unsigned &shield);

    /// @brief constructor
    /// @param type type of immortal moral unit
    /// @param damage amount of damage
    /// @param shield amount of defense
    /// @param restore restore value of health
    /// @param probability probability of restoration
    Immortal_amoral(const immortal_amoral_type &type, const unsigned &damage,
                    const unsigned &shield, const unsigned &restore,
                    const double &probability);

    /// @brief  copy constructor
    /// @param squad    squad to copy
    Immortal_amoral(const Immortal_amoral &squad);

    /// @brief  move constructor
    /// @param squad    squad to move
    Immortal_amoral(Immortal_amoral &&squad);

    ~Immortal_amoral() = default;

    /// @brief  getter of unit type
    /// @return immortal amoral unit type
    immortal_amoral_type get_type() const;

    /// @brief  setter of unit type
    /// @param type new type of immortal amoral unit
    void set_type(const immortal_amoral_type &type);

    /// @brief  func, that can restore some creatures in squad
    void heal() override;

    /// @brief  copy operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Immortal_amoral &operator=(const Immortal_amoral &squad) = default;

    /// @brief  move operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Immortal_amoral &operator=(Immortal_amoral &&squad) = default;

    /// @brief  operator of equality
    /// @param squad squad to check
    /// @return is they equal or not
    bool operator==(const Immortal_amoral &squad);

    /// @brief  operator !=
    /// @param squad squad to check
    /// @return is they eqial or not
    bool operator!=(const Immortal_amoral &squad);
};
}  // namespace squad

#endif