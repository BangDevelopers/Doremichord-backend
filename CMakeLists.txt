cmake_minimum_required(VERSION 3.21)
project(Doremichord_backend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-liconv")

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/sources/*.cpp")

add_executable(Doremichord_backend ${SOURCES} src/main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/ffmpeg_x64/include ${PROJECT_SOURCE_DIR}/jsoncpp/include ${PROJECT_SOURCE_DIR}/src/headers ${PROJECT_SOURCE_DIR}/src/base)
link_directories(${PROJECT_SOURCE_DIR}/ffmpeg_x64/lib ${PROJECT_SOURCE_DIR}/jsoncpp/lib)


target_link_libraries(Doremichord_backend ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/avcodec-58.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/avformat-58.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/avutil-56.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/swresample-3.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/swscale-5.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/avfilter-7.dll ${PROJECT_SOURCE_DIR}/jsoncpp/lib/libjsoncpp.dll.a)
