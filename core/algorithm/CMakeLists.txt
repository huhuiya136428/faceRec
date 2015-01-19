
link_directories(${OpenCV_LIB_DIR})

include_directories(.
    ${OpenCV_INCLUDE_DIRS})

if(NOT USE_SYSTEM_LIBS)
    include_directories(../3rdparty/libconfig)
endif(NOT USE_SYSTEM_LIBS)

#-------------------------------------------------------------------------------
# main
add_library(algorithm
   fzhDefines.hpp
   facedetect.hpp
   facedetect.cpp
   person.hpp
   person.cpp
   )

target_link_libraries(algorithm libopentld cvblobs config++ ${OpenCV_LIBS})

install(TARGETS algorithm DESTINATION bin)

