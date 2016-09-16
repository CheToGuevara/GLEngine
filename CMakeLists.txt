cmake_minimum_required( VERSION 2.8 )
project( GLEngine )

list( APPEND CMAKE_MODULE_PATH
  ${PROJECT_SOURCE_DIR}/CMake
  ${CMAKE_SOURCE_DIR}/CMake/common
  ${CMAKE_SOURCE_DIR}/Externals/include
  ${CMAKE_SOURCE_DIR}/Externals
  )

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
  add_definitions(-DDEBUG)
endif()




# version
set( LAST_RELEASE 0.0.0 )
set( VERSION_MAJOR "0" )
set( VERSION_MINOR "1" )
set( VERSION_PATCH "0" )
set( VERSION_ABI 1 )

# description
set( GLENGINE_DESCRIPTION "GLEngine is a Toolkit for RenderIng and Processing" )
set( COMMON_PROJECT_DOMAIN gmrv.es )

find_package(GLUT REQUIRED)
find_package(FreeImage REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)

add_subdirectory( GLEngine )
