#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <vector>
#include <cstdint>
#define UNITS_PER_SCHOOL (size_t)3

namespace constant
{
    /// @brief school types
    enum class school_type
    {
        ROBOTICS,
        ENERGISER,
        PARALLEL,
        BIOTECH,
        NANOSLIME
    };

    /// @brief units types
    enum class unit
    {
        ROBOMECH,
        CENTRY,
        COLOSSUS,
        GHOST,
        INFESTOR,
        DISRUPTOR,
        ELF,
        GNOME,
        DENDRIOD,
        MARINE,
        CYCLONE,
        REAPER,
        POLTERGEIST,
        TYPHON,
        MIMIC,
        LORD
    };

    /// @brief max quantity of units
    enum class max_quantity
    {
        ROBOMECH = 3,
        CENTRY = 3,
        COLOSSUS = 1,
        GHOST = 2,
        INFESTOR = 1,
        DISRUPTOR = 1,
        ELF = 4,
        GNOME = 5,
        DENDRIOD = 2,
        MARINE = 5,
        CYCLONE = 1,
        REAPER = 5,
        POLTERGEIST = 1,
        TYPHON = 2,
        MIMIC = 5,
        LORD = 1
    };

    /// @brief max health of units
    enum max_health : std::uint32_t
    {
        ROBOMECH = 400,
        CENTRY = 250,
        COLOSSUS = 450,
        GHOST = 500,
        INFESTOR = 350,
        DISRUPTOR = 300,
        ELF = 400,
        GNOME = 600,
        DENDRIOD = 400,
        MARINE = 250,
        CYCLONE = 300,
        REAPER = 350,
        POLTERGEIST = 400,
        TYPHON = 500,
        MIMIC = 250,
        LORD = 1500
    };

    /// @brief speed of units
    enum class speed
    {
        ROBOMECH = 3,
        CENTRY = 3,
        COLOSSUS = 3,
        GHOST = 5,
        INFESTOR = 2,
        DISRUPTOR = 2,
        ELF = 7,
        GNOME = 2,
        DENDRIOD = 2,
        MARINE = 4,
        CYCLONE = 7,
        REAPER = 7,
        POLTERGEIST = 4,
        TYPHON = 3,
        MIMIC = 5,
        LORD = 0
    };

    /// @brief experience of units
    enum class experience
    {
        ROBOMECH = 100,
        CENTRY = 75,
        COLOSSUS = 100,
        GHOST = 125,
        INFESTOR = 100,
        DISRUPTOR = 75,
        ELF = 150,
        GNOME = 125,
        DENDRIOD = 75,
        MARINE = 100,
        CYCLONE = 100,
        REAPER = 75,
        POLTERGEIST = 100,
        TYPHON = 150,
        MIMIC = 50,
        LORD = 250
    };

    /// @brief motivation of units
    enum class motivation
    {
        ROBOMECH = 3,
        CENTRY = 3,
        COLOSSUS = 1,
        GHOST = 2,
        INFESTOR = 1,
        DISRUPTOR = 1,
        ELF = 4,
        GNOME = 5,
        DENDRIOD = 2,
        MARINE = 5,
        CYCLONE = 1,
        REAPER = 5,
        POLTERGEIST = 1,
        TYPHON = 2,
        MIMIC = 5,
        LORD = 5
    };

    /// @brief damage of units
    enum class damage
    {
        ROBOMECH = 3,
        CENTRY = 3,
        COLOSSUS = 1,
        GHOST = 2,
        INFESTOR = 1,
        DISRUPTOR = 1,
        ELF = 4,
        GNOME = 5,
        DENDRIOD = 2,
        MARINE = 5,
        CYCLONE = 1,
        REAPER = 5,
        POLTERGEIST = 1,
        TYPHON = 2,
        MIMIC = 5,
        LORD = 5
    };

    /// @brief defense of units
    enum class defense
    {
        ROBOMECH = 3,
        CENTRY = 3,
        COLOSSUS = 1,
        GHOST = 2,
        INFESTOR = 1,
        DISRUPTOR = 1,
        ELF = 4,
        GNOME = 5,
        DENDRIOD = 2,
        MARINE = 5,
        CYCLONE = 1,
        REAPER = 5,
        POLTERGEIST = 1,
        TYPHON = 2,
        MIMIC = 5,
        LORD = 5
    };
};

#endif