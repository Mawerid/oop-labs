set(HEADER_LIST "${lab2_SOURCE_DIR}/include/conchoid/conchoid.hpp")
add_library(conchoid STATIC conchoid.cpp ${HEADER_LIST})
add_library(dialog STATIC dialog.cpp dialog.hpp)
target_include_directories(conchoid PUBLIC ../include)