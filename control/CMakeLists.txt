

set(QT5_INCLUDE_DIRS ${Qt5_DIR}/include/)
set(QT5_LIB_DIRS ${Qt5_DIR}/lib/)


link_directories(${OpenCV_LIB_DIR}
${QT5_LIB_DIRS})

include_directories(.
    ${OpenCV_INCLUDE_DIRS}
	${QT5_INCLUDE_DIRS})
    


if(NOT USE_SYSTEM_LIBS)
    include_directories(../3rdparty/libconfig)
endif(NOT USE_SYSTEM_LIBS)

#-------------------------------------------------------------------------------
# main
add_library(control
    Buffer.h
	CaptureThread.cpp
	CaptureThread.h
	Config.h
	MatToQImage.cpp
	MatToQImage.h
	ProcessingThread.cpp
	ProcessingThread.h
	SharedImageBuffer.cpp
	SharedImageBuffer.h
	Structures.h
   )

target_link_libraries(control libopentld cvblobs config++ Qt5::Core Qt5::Widgets Qt5::Gui ${OpenCV_LIBS})

install(TARGETS control DESTINATION bin)

