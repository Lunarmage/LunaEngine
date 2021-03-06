cmake_minimum_required(VERSION 2.6)
project(LUNAENGINE)


include_directories(
  src
  contrib
)

if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(LunaEngine
src/engine/Core.cpp
src/engine/Keyboard.cpp
src/engine/Environment.cpp
src/engine/Component.cpp
src/engine/Entity.cpp
src/engine/Resources.cpp
src/engine/Resource.cpp
src/engine/Mesh.cpp
src/engine/MeshRenderer.cpp
src/engine/Transform.cpp
src/engine/Material.cpp
src/engine/Texture.cpp
src/engine/MaterialAttribute.h
src/engine/Shader.cpp
src/engine/VertexBuffer.cpp
src/engine/Camera.cpp



contrib/stb_image/stb_image.cpp
)





add_executable(game
src/game/main.cpp

)

if(MSVC)
  target_link_libraries(game
    SDL2 glew32 opengl32
  )
else()
  target_link_libraries(game
    SDL2 GLU GLEW GL
  )
endif()

target_link_libraries(game LunaEngine)


if(MSVC)
  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:game>"
  )

  add_custom_command(TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:game>"
  )
endif()