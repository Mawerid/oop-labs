set(HEADER_LIST "${lab2_SOURCE_DIR}/include/conchoid.hpp")
add_library(conchoid conchoid.cpp ${HEADER_LIST})
add_library(dialog dialog.cpp dialog.hpp)
target_include_directories(conchoid PUBLIC ../include)