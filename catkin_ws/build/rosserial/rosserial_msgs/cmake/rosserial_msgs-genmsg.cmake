# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rosserial_msgs: 2 messages, 1 services")

set(MSG_I_FLAGS "-Irosserial_msgs:/home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/msg")

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
_generate_msg_cpp(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/msg/Log.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosserial_msgs
)
_generate_msg_cpp(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/msg/TopicInfo.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosserial_msgs
)

### Generating Services
_generate_srv_cpp(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/srv/RequestParam.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosserial_msgs
)

### Generating Module File
_generate_module_cpp(rosserial_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosserial_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rosserial_msgs_gencpp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/msg/Log.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosserial_msgs
)
_generate_msg_lisp(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/msg/TopicInfo.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosserial_msgs
)

### Generating Services
_generate_srv_lisp(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/srv/RequestParam.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosserial_msgs
)

### Generating Module File
_generate_module_lisp(rosserial_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosserial_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(rosserial_msgs_genlisp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/msg/Log.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosserial_msgs
)
_generate_msg_py(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/msg/TopicInfo.msg
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosserial_msgs
)

### Generating Services
_generate_srv_py(rosserial_msgs
  /home/jgrizou/workspace/code/lego/catkin_ws/src/rosserial/rosserial_msgs/srv/RequestParam.srv
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosserial_msgs
)

### Generating Module File
_generate_module_py(rosserial_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosserial_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rosserial_msgs_genpy ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)


debug_message(2 "rosserial_msgs: Iflags=${MSG_I_FLAGS}")


if(gencpp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosserial_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosserial_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosserial_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosserial_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
