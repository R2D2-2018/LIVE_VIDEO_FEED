# Libraries:

add_compile_options(-fexceptions)

link_libraries (gcc)

set (hwlib ${build_environment}/libraries/hwlib)
include_directories (${hwlib}/library)

set (catch ${build_environment}/libraries/Catch2)
include_directories (${catch}/single_include)

# Source Files:

set (sources
    src/sock_exception_handler.cpp
    src/video_codec.cpp
    # place your .cpp's here "src/some_file.cpp"
)
