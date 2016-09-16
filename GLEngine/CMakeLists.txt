source_group( \\ FILES CMakeLists.txt )

set(GLENGINE_PUBLIC_HEADERS

    loaders/MeshLoader.h
    resources/Mesh.h
    resources/Library.h
    scene/Camera.h
    scene/Light.h
    scene/Switch.h
)



set(GLENGINE_SOURCES
	loaders/MeshLoader.cpp
    resources/Mesh.cpp
    resources/Library.cpp
    scene/Camera.cpp
    scene/Light.cpp
    scene/Switch.cpp
)



set(GLENGINE_LINK_LIBRARIES PUBLIC
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
  ${GLUT_LIBRARIES}
)

add_library(GLENGINE ${GLENGINE_SOURCES} ${GLENGINE_PUBLIC_HEADERS} }

target_include_directories(GLENGINE
	${GLENGINE_LINK_LIBRARIES}
	${FREEIMAGE_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIR}
)
target_link_libraries(GLENGINE
	${GLENGINE_LINK_LIBRARIES}
	${FREEIMAGE_LIBRARIES}
    ${GLEW_LIBRARIES}
)

