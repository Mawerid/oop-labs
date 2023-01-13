#ifndef COMMON_UNITS_HPP
#define COMMON_UNITS_HPP

#include "unit.hpp"

namespace squad {
enum amoral_type {
    CENTRY,
    INFESTOR,
    GNOME,
    CYCLONE,
    TYPHON
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
    /// @param new_type type of amoral unit
    Amoral(const amoral_type &type);

    /// @brief   constructor
    /// @param type type of amoral unit
    /// @param damage  amount of damage
    /// @param shield  amoubt of defense
    Amoral(const amoral_type &type, const unsigned &damage,
           const unsigned &shield);

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
};

enum moral_type {
    ROBOMECH,
    GHOST,
    ELF,
    MARINE,
    POLTERGEIST
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
    /// @param type
    /// @param moral
    Moral(const moral_type &type, const int &moral);

    /// @brief  constructor
    /// @param type type of moral unit
    /// @param moral    moral value
    /// @param damage  amount of damage
    /// @param shield  amoubt of defense
    Moral(const moral_type &type, const int &moral,
          const unsigned &damage, const unsigned &shield);

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
};
}  // namespace squad

#endif