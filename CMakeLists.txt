cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(RCOS-EasyContact)

set(LIBHVR Backend/API/libhv)
set(SQLITE Backend/SQLContacts/SQLite)
file(GLOB SOURCE Backend/**/*.cpp)

# Libhv
set(BUILD_STATIC OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(WITH_HTTP_CLIENT OFF CACHE BOOL "" FORCE)

# SQLiteCpp
set(SQLITECPP_RUN_CPPCHECK OFF CACHE BOOL "" FORCE)
set(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "" FORCE)

add_subdirectory(${SQLITE})
add_subdirectory(${LIBHVR})
include_directories(${PROJECT_SOURCE_DIR}/${LIBHVR}/include)
include_directories(${PROJECT_SOURCE_DIR}/${SQLITE}/include/SQLiteCpp)

add_executable(EasyContact ${SOURCE})
set(THREADS_PREFER_PTHREAD_FLAG on)
find_package(Threads REQUIRED)
target_link_libraries(EasyContact
  PUBLIC m
  PUBLIC Threads::Threads
  PUBLIC SQLiteCpp
  PUBLIC hv
)

add_dependencies(EasyContact hv SQLiteCpp)
set_target_properties(EasyContact PROPERTIES CMAKE_CXX_FLAGS "-O2 -Wall -Wextra -g")
