cmake_minimum_required(VERSION 3.21)
project(ProjectName)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
#find_package(PahoMqttCpp REQUIRED)

set(Mosquitto_libs
    /usr/lib/arm-linux-gnueabihf/libmosquitto.so
    /usr/lib/arm-linux-gnueabihf/libmosquitto.so.1)



set(CMAKE_THREAD_PREFER_PTHREAD TRUE) # these are to use the prefered -pthread flag
set(THREADS_PREFER_PTHREAD_FLAG TRUE) # over the -lpthread option
find_package(Threads REQUIRED)

add_executable(parse main.cpp)
set_property(TARGET parse PROPERTY CXX_STANDARD 17)
target_compile_options(parse PRIVATE -Wall -Werror)

target_link_libraries(parse PRIVATE Threads::Threads ${JSONCPP_LIBRARIES} ${Mosquitto_libs})