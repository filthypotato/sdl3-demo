find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_mixer REQUIRED)
find_package(glm REQUIRED)

add_executable (sdl3-demo "sdl3-demo.cpp" "timer.h" "animation.h" "timer.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sdl3-demo PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(sdl3-demo PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_mixer::SDL3_mixer glm::glm)

# Copy resources next to the executable so it can be run from the build directory
add_custom_command(TARGET sdl3-demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/../../resources"
        "$<TARGET_FILE_DIR:sdl3-demo>/resources"
)
