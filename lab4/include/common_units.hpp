#ifndef COMMON_UNITS_HPP
#define COMMON_UNITS_HPP

#include "unit.hpp"

namespace squad {
enum amoral_type {
    CENTRY,
    INFESTOR,
    GNOME,
    CYCLONE,
    TYPHON,
    NONE
};

/// @brief class of amoral unit type
class Amoral : public Unit {
   protected:
    amoral_type type_;

   public:
    /// @brief  convert amoral_type to constant::unit
    /// @param type amoral type to convert
    /// @return equivalent unit type
    constant::unit convert_name(const amoral_type &type) const;

    /// @brief  constructor
    /// @param type type of amoral unit
    Amoral(const amoral_type &type);

    /// @brief  constructor
    /// @param type type of unit
    Amoral(const constant::unit &type);

    /// @brief   constructor
    /// @param type type of amoral unit
    /// @param damage  amount of damage
    /// @param shield  amount of defense
    Amoral(const amoral_type &type, const unsigned &damage,
           const unsigned &shield);

    /// @brief   constructor
    /// @param type type of unit
    /// @param damage  amount of damage
    /// @param shield  amount of defense
    Amoral(const constant::unit &type, const unsigned &damage,
           const unsigned &shield);

    /// @brief  copy constructor
    /// @param squad    squad to copy
    Amoral(const Amoral &squad);

    /// @brief  move constructor
    /// @param squad    squad to move
    Amoral(Amoral &&squad);

    ~Amoral() = default;

    /// @brief  getter of type
    /// @return type of amoral unit
    amoral_type get_type() const;

    /// @brief  setter of type
    /// @param type new type of amoral unit
    void set_type(const amoral_type &type);

    /// @brief  hit other squad
    /// @param squad    squad to hit
    void attack(Squad &squad) const override;

    /// @brief  get damage from other squad
    /// @param squad    squad get hit from
    void defence(Squad &squad) override;

    /// @brief  copy operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Amoral &operator=(const Amoral &squad) = default;

    /// @brief  move operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Amoral &operator=(Amoral &&squad) = default;

    /// @brief  operator of equality
    /// @param squad squad to check
    /// @return is they equal or not
    bool operator==(const Amoral &squad);

    /// @brief  operator !=
    /// @param squad squad to check
    /// @return is they eqial or not
    bool operator!=(const Amoral &squad);
};

enum moral_type {
    ROBOMECH,
    GHOST,
    ELF,
    MARINE,
    POLTERGEIST,
    NONE
};

/// @brief class of moral unit type
class Moral : public Unit {
   protected:
    moral_type type_;
    int moral_ = 0;

   public:
    /// @brief  convert moral_type to constant::unit
    /// @param type moral type to convert
    /// @return equivalent unit type
    constant::unit convert_name(const moral_type &type) const;

    /// @brief  constructor
    /// @param type type of moral unit
    Moral(const moral_type &type);

    /// @brief  constructor
    /// @param type type of unit
    Moral(const constant::unit &type);

    /// @brief  constructor
    /// @param type type of moral unit
    /// @param moral moral value
    Moral(const moral_type &type, const int &moral);

    /// @brief  constructor
    /// @param type type of moral unit
    /// @param moral moral value
    Moral(const constant::unit &type, const int &moral);

    /// @brief  constructor
    /// @param type type of moral unit
    /// @param moral    moral value
    /// @param damage  amount of damage
    /// @param shield  amount of defense
    Moral(const moral_type &type, const int &moral,
          const unsigned &damage, const unsigned &shield);

    /// @brief  constructor
    /// @param type type of unit
    /// @param moral    moral value
    /// @param damage  amount of damage
    /// @param shield  amount of defense
    Moral(const constant::unit &type, const int &moral,
          const unsigned &damage, const unsigned &shield);

    /// @brief  copy constructor
    /// @param squad    squad to copy
    Moral(const Moral &squad);

    /// @brief  move constructor
    /// @param squad    squad to move
    Moral(Moral &&squad);

    ~Moral() = default;

    /// @brief  getter of type
    /// @return type of moral unit
    moral_type get_type() const;

    /// @brief  getter of moral
    /// @return moral value
    int get_moral() const;

    /// @brief  setter of type
    /// @param type new type of amoral unit
    void set_type(const moral_type &type);

    /// @brief  setter of moral
    /// @param moral    new moral value
    void set_moral(const int &moral);

    /// @brief  hit other squad
    /// @param squad    squad to hit
    void attack(Squad &squad) const override;

    /// @brief  get damage from other squad
    /// @param squad    squad get hit from
    void defence(Squad &squad) override;

    /// @brief  func to balance moral near 0
    void balance_moral();

    /// @brief  modificate moral
    /// @param modify    moral value to add
    void modify_moral(const int &modify);

    /// @brief  copy operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Moral &operator=(const Moral &squad) = default;

    /// @brief  move operator of assignment
    /// @param squad    squad to assign
    /// @return new state of class object (this)
    Moral &operator=(Moral &&squad) = default;

    /// @brief  operator of equality
    /// @param squad squad to check
    /// @return is they equal or not
    bool operator==(const Moral &squad);

    /// @brief  operator !=
    /// @param squad squad to check
    /// @return is they eqial or not
    bool operator!=(const Moral &squad);
};
}  // namespace squad

#endif