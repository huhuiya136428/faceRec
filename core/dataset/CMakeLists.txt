
link_directories(${OpenCV_LIB_DIR})

include_directories(.
    ${OpenCV_INCLUDE_DIRS})


#-------------------------------------------------------------------------------
# main
add_library(dataset
   person.hpp
   person.cpp
   )

target_link_libraries(dataset ${OpenCV_LIBS})

install(TARGETS dataset DESTINATION bin)

