cmake_minimum_required(VERSION 3.21)
project(Doremichord_backend)

set(CMAKE_CXX_STANDARD 17)



include_directories(${PROJECT_SOURCE_DIR}/ffmpeg_x64/include)
link_directories(${PROJECT_SOURCE_DIR}/ffmpeg_x64/lib)

add_executable(Doremichord_backend src/main.cpp src/headers/base/ModelRegister.h src/headers/base/Observer.h src/headers/base/Subject.h src/headers/MusicPlayer.h src/headers/MusicInfoModel.h)

target_link_libraries(Doremichord_backend ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/avcodec-58.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/avformat-58.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/avutil-56.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/swresample-3.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/swscale-5.dll ${PROJECT_SOURCE_DIR}/ffmpeg_x64/bin/avfilter-7.dll)
