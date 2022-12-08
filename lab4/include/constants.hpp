#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <cstdint>
#include <cstddef>
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
    enum unit
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
    enum max_quantity
    {
        ROBOMECH_MQ = 3,
        CENTRY_MQ = 3,
        COLOSSUS_MQ = 1,
        GHOST_MQ = 2,
        INFESTOR_MQ = 1,
        DISRUPTOR_MQ = 1,
        ELF_MQ = 4,
        GNOME_MQ = 5,
        DENDRIOD_MQ = 2,
        MARINE_MQ = 5,
        CYCLONE_MQ = 1,
        REAPER_MQ = 5,
        POLTERGEIST_MQ = 1,
        TYPHON_MQ = 2,
        MIMIC_MQ = 5,
        LORD_MQ = 1
    };

    /// @brief max health of units
    enum max_health : std::uint32_t
    {
        ROBOMECH_MH = 400,
        CENTRY_MH = 250,
        COLOSSUS_MH = 450,
        GHOST_MH = 500,
        INFESTOR_MH = 350,
        DISRUPTOR_MH = 300,
        ELF_MH = 400,
        GNOME_MH = 600,
        DENDRIOD_MH = 400,
        MARINE_MH = 250,
        CYCLONE_MH = 300,
        REAPER_MH = 350,
        POLTERGEIST_MH = 400,
        TYPHON_MH = 500,
        MIMIC_MH = 250,
        LORD_MH = 1500
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