# CMake Flags
cmake_minimum_required(VERSION 3.5)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS "-w -O3 -DNDEBUG")
# SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall -Wextra")
# SET(CMAKE_CXX_FLAGS_RELEASE "-w -O3 -DNDEBUG")

PROJECT(EasyContact)

# Library
SET(LIBHVR Backend/API/libhv)
SET(SQLITE Backend/SQLContacts/SQLite)
SET(MAILIO Backend/MailClient/mailio)
file(GLOB SOURCE Backend/**/*.cpp)

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

add_subdirectory(${SQLITE})
add_subdirectory(${LIBHVR})
add_subdirectory(${MAILIO})
include_directories(${PROJECT_SOURCE_DIR}/${LIBHVR}/include)
include_directories(${PROJECT_SOURCE_DIR}/${SQLITE}/include)
include_directories(${PROJECT_SOURCE_DIR}/${MAILIO}/include)

# Compile
add_executable(EasyContact ${SOURCE})
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
