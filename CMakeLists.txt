cmake_minimum_required(VERSION 3.23.2)

project(seamless)

add_executable(${PROJECT_NAME}
    src/main.c
    src/errors.c
    src/net/net.c
    src/net/conn.c
    src/gui/functionalities.c
    src/auth/auth.c

    src/net/sha1.c
    src/net/base64.c
    src/net/qrcodegen.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC include/
    PUBLIC include/net
)

target_link_directories(${PROJECT_NAME}
    PRIVATE lib
)

target_link_libraries(${PROJECT_NAME}
    ws2_32
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
