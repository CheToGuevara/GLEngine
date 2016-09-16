source_group( \\ FILES CMakeLists.txt )

set(GLENGINE_PUBLIC_HEADERS

    loaders/MeshLoader.h
    resources/Mesh.h
    resources/Library.h
    scene/Camera.h
    scene/Light.h
    scene/Switch.h
)

set(GLENGINE_HEADERS

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

common_library( GLENGINE )
