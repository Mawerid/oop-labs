add_library(tile set_tiles.cpp set_tiles.hpp config_tiles.hpp)
target_link_libraries(tile sfml-graphics kdtree cell common immortal lord landscape school skill squad)
target_include_directories(tile PUBLIC ../graphics)
