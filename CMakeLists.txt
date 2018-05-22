cmake_minimum_required(VERSION 2.8.3)
project(resource_resolver)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roslib
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roslib
)

include_directories(include)
include_directories(SYSTEM
  ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
  src/resource_resolver.cpp
)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

if (CATKIN_ENABLE_TESTING)
  find_package(roslint)
  set(ROSLINT_CPP_OPTS "--filter=-build/c++11")
  roslint_cpp()
  roslint_add_test()
endif()
