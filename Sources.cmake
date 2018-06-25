# Libraries:

add_compile_options(-fexceptions)

link_libraries (gcc)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    # Linux specific code
    link_libraries(wsock32 ws2_32)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/sock_exception_handler.cpp
    #src/video_codec.cpp
    src/socket.cpp
    src/UDP.cpp
    # place your .cpp's here "src/some_file.cpp"
)
