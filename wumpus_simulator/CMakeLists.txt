cmake_minimum_required(VERSION 2.8.3)
project(wumpus_simulator)

find_package(catkin REQUIRED COMPONENTS rqt_gui rqt_gui_cpp roscpp message_generation ttb_msgs system_config qt_gui)

find_package(Qt5Core REQUIRED)
get_target_property(Qt5Core_location Qt5::Core LOCATION)
find_package(Qt5Gui REQUIRED)
get_target_property(Qt5Gui_location Qt5::Gui LOCATION)
find_package(Qt5Network REQUIRED)
get_target_property(Qt5Network_location Qt5::Network LOCATION)
find_package(Qt5Widgets REQUIRED)
get_target_property(Qt5Widgets_location Qt5::Widgets LOCATION)
find_package(Qt5WebKitWidgets REQUIRED)
get_target_property(Qt5WebKitWidgets_location Qt5::WebKitWidgets LOCATION)
SET( QT_USE_QTXML TRUE )
SET( QT_WRAP_CPP TRUE )

## Use c++ 11x std
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
if (${CMAKE_EXTRA_GENERATOR} MATCHES "Eclipse CDT4")
	set(CMAKE_CXX_COMPILER_ARG1 "-std=c++11" CACHE STRING "C++ version for eclipse" FORCE)
	set(CMAKE_ECLIPSE_VERSION "4.5" CACHE STRING "Eclipse version" FORCE)
	add_definitions (-DCMAKE_ECLIPSE_GENERATE_SOURCE_PROJECT=TRUE)
endif (${CMAKE_EXTRA_GENERATOR} MATCHES "Eclipse CDT4")

add_message_files(
  FILES
  InitialPoseRequest.msg
  ActionRequest.msg
  ActionResponse.msg
  InitialPoseResponse.msg
)

catkin_python_setup()

generate_messages(
  DEPENDENCIES
  std_msgs
)

set(wumpuswidget_SRCS
  src/wumpus_simulator/WumpusSimulator.cpp
  src/model/Agent.cpp
  src/model/GroundTile.cpp
  src/model/Model.cpp
  src/model/Wumpus.cpp
  src/model/Movable.cpp
)

set(wumpuswidget_HDRS
  include/wumpus_simulator/WumpusSimulator.h 
)

set(wumpuswidget_UIS
  ui/mainwindow_webview.ui
)

set(wumpus_simulator_INCLUDE_DIRECTORIES
    include
    include/model
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Network_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5WebKitWidgets_INCLUDE_DIRS}
    "${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}"
)

if(NOT EXISTS "${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}")
  file(MAKE_DIRECTORY "${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}")
endif()

include_directories(${wumpus_simulator_INCLUDE_DIRECTORIES} ${catkin_INCLUDE_DIRS})

file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)

catkin_package(
  INCLUDE_DIRS ${wumpus_simulator_INCLUDE_DIRECTORIES}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS qt_gui rqt_gui rqt_gui_cpp message_runtime
)

QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT5_WRAP_CPP(wumpus_MOCS ${wumpuswidget_HDRS})
# ensure generated header files are being created in the devel space
set(_cmake_current_binary_dir "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_CURRENT_BINARY_DIR "${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}")
QT5_WRAP_UI(wumpus_UIS_H ${wumpuswidget_UIS})
set(CMAKE_CURRENT_BINARY_DIR "${_cmake_current_binary_dir}")

add_library(${PROJECT_NAME} ${wumpuswidget_SRCS} ${wumpus_MOCS} ${wumpus_UIS_H} ${QT_RESOURCES_CPP})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${Qt5Widgets_location} ${Qt5Core_location} ${Qt5Gui_location} ${Qt5Network_location} ${Qt5WebKitWidgets_location})

add_dependencies(${PROJECT_NAME} wumpus_simulator_generate_messages_cpp)

find_package(class_loader)
class_loader_hide_library_symbols(${PROJECT_NAME})

install(FILES plugin.xml
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(PROGRAMS scripts/wumpus_simulator
  DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)
install(PROGRAMS scripts/wumpus_simulator
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
