#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <cstdint>
#include <cstddef>
#define UNITS_PER_SCHOOL (size_t)3

namespace constant
{
    /// @brief school types
    enum school_type
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
    enum speed
    {
        ROBOMECH_S = 3,
        CENTRY_S = 3,
        COLOSSUS_S = 3,
        GHOST_S = 5,
        INFESTOR_S = 2,
        DISRUPTOR_S = 2,
        ELF_S = 7,
        GNOME_S = 2,
        DENDRIOD_S = 2,
        MARINE_S = 4,
        CYCLONE_S = 7,
        REAPER_S = 7,
        POLTERGEIST_S = 4,
        TYPHON_S = 3,
        MIMIC_S = 5,
        LORD_S = 0
    };

    /// @brief experience of units
    enum experience
    {
        ROBOMECH_EX = 100,
        CENTRY_EX = 75,
        COLOSSUS_EX = 100,
        GHOST_EX = 125,
        INFESTOR_EX = 100,
        DISRUPTOR_EX = 75,
        ELF_EX = 150,
        GNOME_EX = 125,
        DENDRIOD_EX = 75,
        MARINE_EX = 100,
        CYCLONE_EX = 100,
        REAPER_EX = 75,
        POLTERGEIST_EX = 100,
        TYPHON_EX = 150,
        MIMIC_EX = 50,
        LORD_EX = 250
    };

    /// @brief motivation of units
    enum motivation
    {
        ROBOMECH_MT = 3,
        CENTRY_MT = 3,
        COLOSSUS_MT = 1,
        GHOST_MT = 2,
        INFESTOR_MT = 1,
        DISRUPTOR_MT = 1,
        ELF_MT = 4,
        GNOME_MT = 5,
        DENDRIOD_MT = 2,
        MARINE_MT = 5,
        CYCLONE_MT = 1,
        REAPER_MT = 5,
        POLTERGEIST_MT = 1,
        TYPHON_MT = 2,
        MIMIC_MT = 5,
        LORD_MT = 5
    };

    /// @brief damage of units
    enum damage
    {
        ROBOMECH_DM = 3,
        CENTRY_DM = 3,
        COLOSSUS_DM = 1,
        GHOST_DM = 2,
        INFESTOR_DM = 1,
        DISRUPTOR_DM = 1,
        ELF_DM = 4,
        GNOME_DM = 5,
        DENDRIOD_DM = 2,
        MARINE_DM = 5,
        CYCLONE_DM = 1,
        REAPER_DM = 5,
        POLTERGEIST_DM = 1,
        TYPHON_DM = 2,
        MIMIC_DM = 5,
        LORD_DM = 5
    };

    /// @brief defense of units
    enum defense
    {
        ROBOMECH_DF = 3,
        CENTRY_DF = 3,
        COLOSSUS_DF = 1,
        GHOST_DF = 2,
        INFESTOR_DF = 1,
        DISRUPTOR_DF = 1,
        ELF_DF = 4,
        GNOME_DF = 5,
        DENDRIOD_DF = 2,
        MARINE_DF = 5,
        CYCLONE_DF = 1,
        REAPER_DF = 5,
        POLTERGEIST_DF = 1,
        TYPHON_DF = 2,
        MIMIC_DF = 5,
        LORD_DF = 5
    };
};

#endif