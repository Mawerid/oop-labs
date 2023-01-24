#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#define UNITS_PER_SCHOOL (size_t)3
#define UNITS_COUNT (size_t)15
#define START_ENERGY 100
#define START_MAX_ENERGY 1000
#define MAP_SIZE_VERTICAL 10
#define MAP_SIZE_HORIZONTAL 19
#define OBSTACLES_COUNT 10
#define COEF_MIN_STUDY 3

namespace constant {
/// @brief school types
enum school_type : unsigned {
    ROBOTICS,
    ENERGISER,
    PARALLEL,
    BIOTECH,
    NANOSLIME
};

/// @brief units types
enum unit : unsigned {
    ROBOMECH,
    CENTRY,
    COLOSSUS,
    GHOST,
    INFESTOR,
    DISRUPTOR,
    ELF,
    GNOME,
    DENDROID,
    MARINE,
    CYCLONE,
    REAPER,
    POLTERGEIST,
    TYPHON,
    MIMIC,
    LORD
};
static const std::vector<std::string> unit_type =
    {std::string("M"), std::string("A"), std::string("IA"), std::string("M"),
     std::string("A"), std::string("IA"), std::string("M"), std::string("A"),
     std::string("IM"), std::string("M"), std::string("A"), std::string("IM"),
     std::string("M"), std::string("A"), std::string("IM"), std::string("L")};

/// @brief max quantity of units
enum max_quantity_set : unsigned {
    ROBOMECH_MQ = 3,
    CENTRY_MQ = 3,
    COLOSSUS_MQ = 1,
    GHOST_MQ = 2,
    INFESTOR_MQ = 1,
    DISRUPTOR_MQ = 1,
    ELF_MQ = 4,
    GNOME_MQ = 5,
    DENDROID_MQ = 2,
    MARINE_MQ = 5,
    CYCLONE_MQ = 1,
    REAPER_MQ = 5,
    POLTERGEIST_MQ = 1,
    TYPHON_MQ = 2,
    MIMIC_MQ = 5,
    LORD_MQ = 1
};
static const std::vector<unsigned> max_quantity =
    {ROBOMECH_MQ, CENTRY_MQ, COLOSSUS_MQ, GHOST_MQ, INFESTOR_MQ,
     DISRUPTOR_MQ, ELF_MQ, GNOME_MQ, DENDROID_MQ, MARINE_MQ, CYCLONE_MQ, REAPER_MQ, POLTERGEIST_MQ, TYPHON_MQ, MIMIC_MQ, LORD_MQ};

/// @brief max health of units
enum max_health_set : unsigned {
    ROBOMECH_MH = 400,
    CENTRY_MH = 250,
    COLOSSUS_MH = 450,
    GHOST_MH = 500,
    INFESTOR_MH = 350,
    DISRUPTOR_MH = 300,
    ELF_MH = 400,
    GNOME_MH = 600,
    DENDROID_MH = 400,
    MARINE_MH = 250,
    CYCLONE_MH = 300,
    REAPER_MH = 350,
    POLTERGEIST_MH = 400,
    TYPHON_MH = 500,
    MIMIC_MH = 250,
    LORD_MH = 1500
};
static const std::vector<unsigned> max_health =
    {ROBOMECH_MH, CENTRY_MH, COLOSSUS_MH, GHOST_MH, INFESTOR_MH,
     DISRUPTOR_MH, ELF_MH, GNOME_MH, DENDROID_MH, MARINE_MH, CYCLONE_MH, REAPER_MH, POLTERGEIST_MH, TYPHON_MH, MIMIC_MH, LORD_MH};

/// @brief speed of units
enum speed_set : unsigned {
    ROBOMECH_S = 3,
    CENTRY_S = 3,
    COLOSSUS_S = 3,
    GHOST_S = 5,
    INFESTOR_S = 2,
    DISRUPTOR_S = 2,
    ELF_S = 7,
    GNOME_S = 2,
    DENDROID_S = 2,
    MARINE_S = 4,
    CYCLONE_S = 7,
    REAPER_S = 7,
    POLTERGEIST_S = 4,
    TYPHON_S = 3,
    MIMIC_S = 5,
    LORD_S = 0
};
static const std::vector<unsigned> speed =
    {ROBOMECH_S, CENTRY_S, COLOSSUS_S, GHOST_S, INFESTOR_S,
     DISRUPTOR_S, ELF_S, GNOME_S, DENDROID_S, MARINE_S, CYCLONE_S,
     REAPER_S, POLTERGEIST_S, TYPHON_S, MIMIC_S, LORD_S};

/// @brief experience of units
enum experience_set : unsigned {
    ROBOMECH_EX = 100,
    CENTRY_EX = 75,
    COLOSSUS_EX = 100,
    GHOST_EX = 125,
    INFESTOR_EX = 100,
    DISRUPTOR_EX = 75,
    ELF_EX = 150,
    GNOME_EX = 125,
    DENDROID_EX = 75,
    MARINE_EX = 100,
    CYCLONE_EX = 100,
    REAPER_EX = 75,
    POLTERGEIST_EX = 100,
    TYPHON_EX = 150,
    MIMIC_EX = 50,
    LORD_EX = 250
};
static const std::vector<unsigned> experience =
    {ROBOMECH_EX, CENTRY_EX, COLOSSUS_EX, GHOST_EX, INFESTOR_EX,
     DISRUPTOR_EX, ELF_EX, GNOME_EX, DENDROID_EX, MARINE_EX, CYCLONE_EX,
     REAPER_EX, POLTERGEIST_EX, TYPHON_EX, MIMIC_EX, LORD_EX};

/// @brief motivation of units
enum motivation_set : unsigned {
    ROBOMECH_MT = 3,
    CENTRY_MT = 3,
    COLOSSUS_MT = 1,
    GHOST_MT = 2,
    INFESTOR_MT = 1,
    DISRUPTOR_MT = 1,
    ELF_MT = 4,
    GNOME_MT = 5,
    DENDROID_MT = 2,
    MARINE_MT = 5,
    CYCLONE_MT = 1,
    REAPER_MT = 5,
    POLTERGEIST_MT = 1,
    TYPHON_MT = 2,
    MIMIC_MT = 5,
    LORD_MT = 5
};
static const std::vector<unsigned> motivation =
    {ROBOMECH_MT, CENTRY_MT, COLOSSUS_MT, GHOST_MT, INFESTOR_MT,
     DISRUPTOR_MT, ELF_MT, GNOME_MT, DENDROID_MT, MARINE_MT, CYCLONE_MT,
     REAPER_MT, POLTERGEIST_MT, TYPHON_MT, MIMIC_MT, LORD_MT};

/// @brief damage of units
enum damage_set : unsigned {
    ROBOMECH_DM = 30,
    CENTRY_DM = 30,
    COLOSSUS_DM = 10,
    GHOST_DM = 20,
    INFESTOR_DM = 10,
    DISRUPTOR_DM = 10,
    ELF_DM = 40,
    GNOME_DM = 50,
    DENDROID_DM = 20,
    MARINE_DM = 50,
    CYCLONE_DM = 10,
    REAPER_DM = 50,
    POLTERGEIST_DM = 10,
    TYPHON_DM = 20,
    MIMIC_DM = 50,
    LORD_DM = 50
};
static const std::vector<unsigned> damage =
    {ROBOMECH_DM, CENTRY_DM, COLOSSUS_DM, GHOST_DM, INFESTOR_DM,
     DISRUPTOR_DM, ELF_DM, GNOME_DM, DENDROID_DM, MARINE_DM, CYCLONE_DM,
     REAPER_DM, POLTERGEIST_DM, TYPHON_DM, MIMIC_DM, LORD_DM};

/// @brief defense of units
enum shield_set : unsigned {
    ROBOMECH_DF = 3,
    CENTRY_DF = 3,
    COLOSSUS_DF = 1,
    GHOST_DF = 2,
    INFESTOR_DF = 1,
    DISRUPTOR_DF = 1,
    ELF_DF = 4,
    GNOME_DF = 5,
    DENDROID_DF = 2,
    MARINE_DF = 5,
    CYCLONE_DF = 1,
    REAPER_DF = 5,
    POLTERGEIST_DF = 1,
    TYPHON_DF = 2,
    MIMIC_DF = 5,
    LORD_DF = 5
};
static const std::vector<unsigned> shield =
    {ROBOMECH_DF, CENTRY_DF, COLOSSUS_DF, GHOST_DF, INFESTOR_DF,
     DISRUPTOR_DF, ELF_DF, GNOME_DF, DENDROID_DF, MARINE_DF, CYCLONE_DF,
     REAPER_DF, POLTERGEIST_DF, TYPHON_DF, MIMIC_DF, LORD_DF};

/// @brief energy to call the units
enum energy_set : unsigned {
    ROBOMECH_ENR = 30,
    CENTRY_ENR = 30,
    COLOSSUS_ENR = 10,
    GHOST_ENR = 20,
    INFESTOR_ENR = 10,
    DISRUPTOR_ENR = 10,
    ELF_ENR = 40,
    GNOME_ENR = 50,
    DENDROID_ENR = 20,
    MARINE_ENR = 50,
    CYCLONE_ENR = 10,
    REAPER_ENR = 50,
    POLTERGEIST_ENR = 10,
    TYPHON_ENR = 20,
    MIMIC_ENR = 50,
    LORD_ENR = 50
};
static const std::vector<unsigned> energy =
    {ROBOMECH_ENR, CENTRY_ENR, COLOSSUS_ENR, GHOST_ENR, INFESTOR_ENR,
     DISRUPTOR_ENR, ELF_ENR, GNOME_ENR, DENDROID_ENR, MARINE_ENR, CYCLONE_ENR,
     REAPER_ENR, POLTERGEIST_ENR, TYPHON_ENR, MIMIC_ENR, LORD_ENR};

};  // namespace constant

#endif