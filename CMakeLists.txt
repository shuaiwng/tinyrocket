cmake_minimum_required(VERSION 3.5)

project(tinyrocket LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Provide the header files and the library files
if (WIN32)
    include_directories(
        "C:/devtools/SDL2-mingw/SDL2/x86_64-w64-mingw32/include"
    )
    link_directories("C:/devtools/SDL2-mingw/SDL2/x86_64-w64-mingw32/lib")
endif()
if (UNIX)
    include_directories(
        "/user/local/include"
    )
    link_directories("/usr/local/lib")
endif()


set(SRCS
    main.cpp
    camera.cpp
    gameobject.cpp
    background.cpp
)
set(ASSETS
    assets/bg.png
    assets/bg_d_raw.png
    assets/bg_t_raw.png
    assets/image.py
    assets/rocket.png
)
add_executable(${CMAKE_PROJECT_NAME}
    ${SRCS}
    ${ASSETS}
)


# Link binaries to the executable
if (WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME} mingw32 SDL2main SDL2 SDL2_image)
endif()
if (UNIX)
    target_link_libraries(${CMAKE_PROJECT_NAME} SDL2 SDL2_image)
endif()


# copy the assets folder into the build directory
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/assets")


install(TARGETS ${CMAKE_PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
