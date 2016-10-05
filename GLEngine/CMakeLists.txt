source_group( \\ FILES CMakeLists.txt )

set(GLENGINE_PUBLIC_HEADERS
	config.h

    resources/Mesh.h
    resources/Library.h
	resources/Material.h
	resources/Texture.h
    scene/Camera.h
    scene/Light.h
    scene/Switch.h
	scene/Node.h
)



set(GLENGINE_SOURCES
	main.cpp

    resources/Mesh.cpp
    resources/Library.cpp
	resources/Material.cpp
	resources/Texture.cpp
    scene/Camera.cpp
    scene/Light.cpp
    scene/Switch.cpp
	scene/Node.cpp
)

FILE(GLOB_RECURSE SHADERS
    ${CMAKE_CURRENT_DIR} shaders/*.[a-z]*)


find_package(Assimp REQUIRED)



set(GLENGINE_LINK_LIBRARIES PUBLIC
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
  ${GLUT_LIBRARIES}
)

add_executable(GLENGINE ${GLENGINE_SOURCES} ${GLENGINE_PUBLIC_HEADERS} )

target_include_directories(GLENGINE PUBLIC
	${FREEIMAGE_INCLUDE_DIRS}
	${ASSIMP_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIR}
)
target_link_libraries(GLENGINE
	${GLENGINE_LINK_LIBRARIES}
	${ASSIMP_LIBRARIES}
	${FREEIMAGE_LIBRARIES}
    ${GLEW_LIBRARIES}
)

FILE(INSTALL shaders/ DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders/)

