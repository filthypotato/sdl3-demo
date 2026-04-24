cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("sdl3-demo" LANGUAGES C CXX)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_mixer REQUIRED)
find_package(glm REQUIRED)

add_executable(sdl3-demo
    "sdl3-demo/sdl3-demo/sdl3-demo.cpp"
    "sdl3-demo/sdl3-demo/timer.h"
    "sdl3-demo/sdl3-demo/animation.h"
)

set_property(TARGET sdl3-demo PROPERTY CXX_STANDARD 20)

target_link_libraries(sdl3-demo PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_mixer::SDL3_mixer glm::glm)

# Copy resources next to the executable
add_custom_command(TARGET sdl3-demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/resources"
        "$<TARGET_FILE_DIR:sdl3-demo>/resources"
)
