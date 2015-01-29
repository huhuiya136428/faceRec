
set(QT5_INCLUDE_DIRS ${Qt5_DIR}/include/)
set(QT5_LIB_DIRS ${Qt5_DIR}/lib/)


link_directories(${OpenCV_LIB_DIR}
${QT5_LIB_DIRS}
D:/development/projects/faceRec/build/x64/Debug
	D:/development/projects/faceRec/build/x64/release)

include_directories(.
../control/
    ${OpenCV_INCLUDE_DIRS}
	${QT5_INCLUDE_DIRS})


if(NOT USE_SYSTEM_LIBS)
    include_directories(../3rdparty/libconfig)
endif(NOT USE_SYSTEM_LIBS)


#-------------------------------------------------------------------------------
# main
set(UI_FILES
    CameraConnectDialog.ui
    CameraView.ui
	ImageProcessingSettingsDialog.ui
	MainWindow.ui
	)	


set(SOURCE_FILES
    	CameraConnectDialog.cpp
	CameraView.cpp
	FrameLabel.cpp
	ImageProcessingSettingsDialog.cpp
	main.cpp
	MainWindow.cpp
	)

set(INCLUDE_FILES
	 CameraConnectDialog.h	
	CameraView.h	
	FrameLabel.h	
	ImageProcessingSettingsDialog.h
	MainWindow.h	
	)


#add_library(frontend ${INCLUDE_FILES} ${SOURCE_FILES} ${UI_FILES})
source_group("Header Files" FILES ${INCLUDE_FILES})

source_group("Source Files" FILES ${SOURCE_FILES})
#add_library(frontend ${SOURCE_FILES})

#add_library(frontend ${UI_FILES})
source_group("UI forms" FILES ${UI_FILES})
   
set(ICONS 
./resources/icon.qrc
)


#-------------------------------------------------------------------------------
# opentld
add_executable(frontend
    ${INCLUDE_FILES} ${SOURCE_FILES} ${UI_FILES} ${ICONS})
	
target_link_libraries(frontend libopentld cvblobs config++ control dataset algorithm Qt5::Core Qt5::Widgets Qt5::Gui ${OpenCV_LIBS})

#install(TARGETS faceRec DESTINATION bin)

