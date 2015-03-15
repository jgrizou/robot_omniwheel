# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "roslego: 2 messages, 0 services")

set(MSG_I_FLAGS "-Iroslego:/home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg;-Istd_msgs:/opt/ros/groovy/share/std_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

#better way to handle this?
set (ALL_GEN_OUTPUT_FILES_cpp "")

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(roslego
  /home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg/motor_action.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/roslego
)
_generate_msg_cpp(roslego
  /home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg/ahrs.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/roslego
)

### Generating Services

### Generating Module File
_generate_module_cpp(roslego
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/roslego
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(roslego_gencpp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(roslego
  /home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg/motor_action.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/roslego
)
_generate_msg_lisp(roslego
  /home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg/ahrs.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/roslego
)

### Generating Services

### Generating Module File
_generate_module_lisp(roslego
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/roslego
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(roslego_genlisp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(roslego
  /home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg/motor_action.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/roslego
)
_generate_msg_py(roslego
  /home/jgrizou/workspace/code/lego/catkin_ws/src/roslego/msg/ahrs.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/roslego
)

### Generating Services

### Generating Module File
_generate_module_py(roslego
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/roslego
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(roslego_genpy ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)


debug_message(2 "roslego: Iflags=${MSG_I_FLAGS}")


if(gencpp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/roslego
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(roslego_gencpp std_msgs_gencpp)

if(genlisp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/roslego
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(roslego_genlisp std_msgs_genlisp)

if(genpy_INSTALL_DIR)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/roslego\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/roslego
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(roslego_genpy std_msgs_genpy)
