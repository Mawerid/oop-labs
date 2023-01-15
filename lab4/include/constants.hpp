#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <cstddef>
#include <cstdint>
#include <vector>
#define UNITS_PER_SCHOOL (size_t)3
#define UNITS_COUNT (size_t)15
#define START_ENERGY 100
#define START_MAX_ENERGY 1000
#define MAP_SIZE {10, 15}

namespace constant {
/// @brief school types
enum school_type : std::uint32_t {
    ROBOTICS,
    ENERGISER,
    PARALLEL,
    BIOTECH,
    NANOSLIME
};

/// @brief units types
enum unit : std::uint32_t {
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
static const std::vector<std::string> unit_type =
    {"M", "A", "IA", "M", "A", "IA", "M", "A", "IM",
     "M", "A", "IM", "M", "A", "IM", "L"};

/// @brief max quantity of units
enum max_quantity_set : std::uint32_t {
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
static const std::vector<uint32_t> max_quantity =
    {ROBOMECH_MQ, CENTRY_MQ, COLOSSUS_MQ, GHOST_MQ, INFESTOR_MQ,
     DISRUPTOR_MQ, ELF_MQ, GNOME_MQ, DENDRIOD_MQ, MARINE_MQ, CYCLONE_MQ, REAPER_MQ, POLTERGEIST_MQ, TYPHON_MQ, MIMIC_MQ, LORD_MQ};

/// @brief max health of units
enum max_health_set : std::uint32_t {
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
static const std::vector<uint32_t> max_health =
    {ROBOMECH_MH, CENTRY_MH, COLOSSUS_MH, GHOST_MH, INFESTOR_MH,
     DISRUPTOR_MH, ELF_MH, GNOME_MH, DENDRIOD_MH, MARINE_MH, CYCLONE_MH, REAPER_MH, POLTERGEIST_MH, TYPHON_MH, MIMIC_MH, LORD_MH};

/// @brief speed of units
enum speed_set : std::uint32_t {
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
static const std::vector<uint32_t> speed =
    {ROBOMECH_S, CENTRY_S, COLOSSUS_S, GHOST_S, INFESTOR_S,
     DISRUPTOR_S, ELF_S, GNOME_S, DENDRIOD_S, MARINE_S, CYCLONE_S,
     REAPER_S, POLTERGEIST_S, TYPHON_S, MIMIC_S, LORD_S};

/// @brief experience of units
enum experience_set : std::uint32_t {
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
static const std::vector<uint32_t> experience =
    {ROBOMECH_EX, CENTRY_EX, COLOSSUS_EX, GHOST_EX, INFESTOR_EX,
     DISRUPTOR_EX, ELF_EX, GNOME_EX, DENDRIOD_EX, MARINE_EX, CYCLONE_EX,
     REAPER_EX, POLTERGEIST_EX, TYPHON_EX, MIMIC_EX, LORD_EX};

/// @brief motivation of units
enum motivation_set : std::uint32_t {
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
static const std::vector<uint32_t> motivation =
    {ROBOMECH_MT, CENTRY_MT, COLOSSUS_MT, GHOST_MT, INFESTOR_MT,
     DISRUPTOR_MT, ELF_MT, GNOME_MT, DENDRIOD_MT, MARINE_MT, CYCLONE_MT,
     REAPER_MT, POLTERGEIST_MT, TYPHON_MT, MIMIC_MT, LORD_MT};

/// @brief damage of units
enum damage_set : std::uint32_t {
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
static const std::vector<uint32_t> damage =
    {ROBOMECH_DM, CENTRY_DM, COLOSSUS_DM, GHOST_DM, INFESTOR_DM,
     DISRUPTOR_DM, ELF_DM, GNOME_DM, DENDRIOD_DM, MARINE_DM, CYCLONE_DM,
     REAPER_DM, POLTERGEIST_DM, TYPHON_DM, MIMIC_DM, LORD_DM};

/// @brief defense of units
enum shield_set : std::uint32_t {
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
static const std::vector<uint32_t> shield =
    {ROBOMECH_DF, CENTRY_DF, COLOSSUS_DF, GHOST_DF, INFESTOR_DF,
     DISRUPTOR_DF, ELF_DF, GNOME_DF, DENDRIOD_DF, MARINE_DF, CYCLONE_DF,
     REAPER_DF, POLTERGEIST_DF, TYPHON_DF, MIMIC_DF, LORD_DF};

/// @brief energy to call the units
enum energy_set : std::uint32_t {
    ROBOMECH_ENR = 3,
    CENTRY_ENR = 3,
    COLOSSUS_ENR = 1,
    GHOST_ENR = 2,
    INFESTOR_ENR = 1,
    DISRUPTOR_ENR = 1,
    ELF_ENR = 4,
    GNOME_ENR = 5,
    DENDRIOD_ENR = 2,
    MARINE_ENR = 5,
    CYCLONE_ENR = 1,
    REAPER_ENR = 5,
    POLTERGEIST_ENR = 1,
    TYPHON_ENR = 2,
    MIMIC_ENR = 5,
    LORD_ENR = 5
};
static const std::vector<uint32_t> energy =
    {ROBOMECH_ENR, CENTRY_ENR, COLOSSUS_ENR, GHOST_ENR, INFESTOR_ENR,
     DISRUPTOR_ENR, ELF_ENR, GNOME_ENR, DENDRIOD_ENR, MARINE_ENR, CYCLONE_ENR,
     REAPER_ENR, POLTERGEIST_ENR, TYPHON_ENR, MIMIC_ENR, LORD_ENR};

};  // namespace constant

#endif