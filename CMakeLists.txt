cmake_minimum_required(VERSION ${CMAKE_VERSION})
 project(MYENGINE)

add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
  src
)


  include_directories(
    contrib/cl-windows-x86_64/include
  )

  link_directories(
    contrib/cl-windows-x86_64/lib
  )

add_library(rend
  src/rend/Animation.cpp
  src/rend/Buffer.cpp
  src/rend/Debug.cpp
  src/rend/Font.cpp
  src/rend/Mesh.cpp
  src/rend/Model.cpp
  src/rend/ModelShader.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/TextShader.cpp
  src/rend/Texture.cpp
  src/rend/rendmath.cpp
  src/rend/utils.cpp
)
  target_link_libraries(rend glew32 opengl32 )

add_library(leap
  src/leap/ExampleConnection.h
  src/leap/ExampleConnection.c
  src/leap/LeapSample.c
)
  target_link_libraries(leap leapc)

add_library(myengine
  src/myengine/myengine.h
  src/myengine/Core.h
  src/myengine/Core.cpp
  src/myengine/Window.h
  src/myengine/Window.cpp
  src/myengine/Component.h
  src/myengine/Component.cpp
  src/myengine/Entity.h
  src/myengine/Entity.cpp
  src/myengine/Texture.h
  src/myengine/Texture.cpp
  src/myengine/Transform.h
  src/myengine/Transform.cpp
  src/myengine/TriangleRenderer.h
  src/myengine/TriangleRenderer.cpp
  src/myengine/ModelRenderer.h
  src/myengine/ModelRenderer.cpp
  src/myengine/Resource.h
  src/myengine/Resource.cpp
  src/myengine/Resources.h
  src/myengine/Resources.cpp
  src/myengine/Sound.h
  src/myengine/Sound.cpp
  src/myengine/Model.h
  src/myengine/Model.cpp
  src/myengine/Keyboard.h
  src/myengine/Keyboard.cpp
  src/myengine/Camera.h
  src/myengine/Camera.cpp
  src/myengine/HandTransform.h
  src/myengine/HandTransform.cpp

 )
target_link_libraries(myengine rend leap SDL2 openal32 leapc)


add_executable(demo
  src/demo/main.cpp
  src/demo/Employee.h
  src/demo/Employee.cpp
 )
target_link_libraries(demo myengine)

