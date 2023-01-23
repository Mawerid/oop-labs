add_library(graphics set_tiles.cpp set_tiles.hpp config_textures.hpp)
target_link_libraries(graphics sfml-graphics cell common immortal lord landscape school skill squad)
target_include_directories(graphics PUBLIC ../graphics)
