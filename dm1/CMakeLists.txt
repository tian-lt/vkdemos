project(dm1)

find_package(glfw3 CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

set(DM1_HEADER_FILES
    inc/prereq.hpp
    inc/app.hpp
    inc/vkinstance.hpp
    inc/vkldevice.hpp
    inc/vkpdevice.hpp
    inc/vksurface.hpp
)

set(DM1_SOURCE_FILES
    src/app.cpp
    src/main.cpp
    src/vkinstance.cpp
    src/vkldevice.cpp
    src/vkpdevice.cpp
)

add_executable(dm1
    ${DM1_SOURCE_FILES}
    ${DM1_HEADER_FILES} # for IDC searching convenience
)

target_include_directories(dm1 PRIVATE inc)
target_include_directories(dm1 PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(dm1 PRIVATE glfw)
target_link_libraries(dm1 PRIVATE ${Vulkan_LIBRARIES})


