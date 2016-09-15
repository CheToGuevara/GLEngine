cmake_minimum_required( VERSION 2.8 )
project( GLEngine )

list( APPEND CMAKE_MODULE_PATH
  ${PROJECT_SOURCE_DIR}/CMake
  ${CMAKE_SOURCE_DIR}/CMake/common )

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
  add_definitions(-DDEBUG)
endif()

include( GitExternal )

# version
set( LAST_RELEASE 0.0.0 )
set( VERSION_MAJOR "0" )
set( VERSION_MINOR "1" )
set( VERSION_PATCH "0" )
set( VERSION_ABI 1 )

# description
set( GLENGINE_DESCRIPTION "GLEngine is a Toolkit for RenderIng and Processing" )
set( COMMON_PROJECT_DOMAIN gmrv.es )

include(Common)

common_package( Eigen3 REQUIRED SYSTEM )
common_package( GLUT REQUIRED SYSTEM )
common_package( GLEW REQUIRED SYSTEM )
common_package( OpenGL REQUIRED SYSTEM )
common_package_post( )

add_subdirectory( GLEngine )

include( CPackConfig )
