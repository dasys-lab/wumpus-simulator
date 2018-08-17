# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "wumpus_simulator: 4 messages, 0 services")

set(MSG_I_FLAGS "-Iwumpus_simulator:/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(wumpus_simulator_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg" NAME_WE)
add_custom_target(_wumpus_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wumpus_simulator" "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg" ""
)

get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg" NAME_WE)
add_custom_target(_wumpus_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wumpus_simulator" "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg" ""
)

get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg" NAME_WE)
add_custom_target(_wumpus_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wumpus_simulator" "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg" ""
)

get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg" NAME_WE)
add_custom_target(_wumpus_simulator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "wumpus_simulator" "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_cpp(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_cpp(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_cpp(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wumpus_simulator
)

### Generating Services

### Generating Module File
_generate_module_cpp(wumpus_simulator
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wumpus_simulator
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(wumpus_simulator_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(wumpus_simulator_generate_messages wumpus_simulator_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_cpp _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_cpp _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_cpp _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_cpp _wumpus_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(wumpus_simulator_gencpp)
add_dependencies(wumpus_simulator_gencpp wumpus_simulator_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wumpus_simulator_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_eus(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_eus(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_eus(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/wumpus_simulator
)

### Generating Services

### Generating Module File
_generate_module_eus(wumpus_simulator
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/wumpus_simulator
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(wumpus_simulator_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(wumpus_simulator_generate_messages wumpus_simulator_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_eus _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_eus _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_eus _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_eus _wumpus_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(wumpus_simulator_geneus)
add_dependencies(wumpus_simulator_geneus wumpus_simulator_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wumpus_simulator_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_lisp(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_lisp(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_lisp(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wumpus_simulator
)

### Generating Services

### Generating Module File
_generate_module_lisp(wumpus_simulator
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wumpus_simulator
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(wumpus_simulator_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(wumpus_simulator_generate_messages wumpus_simulator_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_lisp _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_lisp _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_lisp _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_lisp _wumpus_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(wumpus_simulator_genlisp)
add_dependencies(wumpus_simulator_genlisp wumpus_simulator_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wumpus_simulator_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_nodejs(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_nodejs(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_nodejs(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/wumpus_simulator
)

### Generating Services

### Generating Module File
_generate_module_nodejs(wumpus_simulator
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/wumpus_simulator
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(wumpus_simulator_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(wumpus_simulator_generate_messages wumpus_simulator_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_nodejs _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_nodejs _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_nodejs _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_nodejs _wumpus_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(wumpus_simulator_gennodejs)
add_dependencies(wumpus_simulator_gennodejs wumpus_simulator_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wumpus_simulator_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_py(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_py(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator
)
_generate_msg_py(wumpus_simulator
  "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator
)

### Generating Services

### Generating Module File
_generate_module_py(wumpus_simulator
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(wumpus_simulator_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(wumpus_simulator_generate_messages wumpus_simulator_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_py _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/InitialPoseRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_py _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionResponse.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_py _wumpus_simulator_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/emmeda/Research/dev/ttbws/src/cnc-turtlebots/wumpus_simulator/msg/ActionRequest.msg" NAME_WE)
add_dependencies(wumpus_simulator_generate_messages_py _wumpus_simulator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(wumpus_simulator_genpy)
add_dependencies(wumpus_simulator_genpy wumpus_simulator_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wumpus_simulator_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wumpus_simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wumpus_simulator
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(wumpus_simulator_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/wumpus_simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/wumpus_simulator
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(wumpus_simulator_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wumpus_simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wumpus_simulator
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(wumpus_simulator_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/wumpus_simulator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/wumpus_simulator
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(wumpus_simulator_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator
    DESTINATION ${genpy_INSTALL_DIR}
    # skip all init files
    PATTERN "__init__.py" EXCLUDE
    PATTERN "__init__.pyc" EXCLUDE
  )
  # install init files which are not in the root folder of the generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator
    DESTINATION ${genpy_INSTALL_DIR}
    FILES_MATCHING
    REGEX "${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wumpus_simulator/.+/__init__.pyc?$"
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(wumpus_simulator_generate_messages_py std_msgs_generate_messages_py)
endif()
