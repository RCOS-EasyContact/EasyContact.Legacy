# CMake Flags
cmake_minimum_required(VERSION 3.5)
PROJECT(EasyContact VERSION 0.43)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
# cmake -DCMAKE_BUILD_TYPE=Debug .
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall -Wextra")
# cmake -DCMAKE_BUILD_TYPE=Release .
SET(CMAKE_CXX_FLAGS_RELEASE "-w -O3 -DNDEBUG")
SET(BIN_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bin")
SET(INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include")

# Library
SET(LIBHVR lib/libhv)
SET(SQLITE lib/SQLite)
SET(MAILIO lib/mailio)
file(GLOB SOURCE
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB HEADERS
  "${PROJECT_SOURCE_DIR}/include/EasyContact/*.hpp"
)

# Libhv
SET(BUILD_STATIC OFF CACHE BOOL "" FORCE)
SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
SET(WITH_HTTP_CLIENT OFF CACHE BOOL "" FORCE)

# SQLiteCpp
SET(SQLITECPP_RUN_CPPCHECK OFF CACHE BOOL "" FORCE)
SET(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "" FORCE)

# Mailio
SET(MAILIO_BUILD_DOCUMENTATION OFF CACHE BOOL "" FORCE)
SET(MAILIO_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# SubModules Directory
add_subdirectory(${SQLITE})
add_subdirectory(${LIBHVR})
add_subdirectory(${MAILIO})
include_directories(${PROJECT_SOURCE_DIR}/${LIBHVR}/include)
include_directories(${PROJECT_SOURCE_DIR}/${SQLITE}/include)
include_directories(${PROJECT_SOURCE_DIR}/${MAILIO}/include)

# Compile
add_executable(EasyContact ${SOURCE} ${HEADERS})
target_include_directories(EasyContact PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/EasyContact>
  $<INSTALL_INTERFACE:include/EasyContact>
)
SET(THREADS_PREFER_PTHREAD_FLAG on)
find_package(Threads REQUIRED)
target_link_libraries(EasyContact
  PUBLIC m
  PUBLIC Threads::Threads
  PUBLIC SQLiteCpp
  PUBLIC hv
  PUBLIC mailio
)
add_dependencies(EasyContact hv SQLiteCpp)
