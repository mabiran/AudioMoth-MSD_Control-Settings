# fatfs CMake file
project(fatfs)

# find . -name '*.c' | sort -u
add_library(${PROJECT_NAME}
    src/audioMoth_ff.c
    src/diskio.c)

target_include_directories(${PROJECT_NAME} PUBLIC
    inc
    ../efm32-base/hardware/kit/common/drivers
    ../inc)

target_link_libraries(${PROJECT_NAME} emlib)
