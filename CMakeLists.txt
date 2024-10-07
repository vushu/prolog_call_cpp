cmake_minimum_required(VERSION 3.20...3.28)
project(prolog_call_cpp)

# add_subdirectory(backend)
add_subdirectory(prolog)

enable_testing()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_subdirectory(backend)

# file(GLOB_RECURSE SOURCE_LIST "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
# file(GLOB_RECURSE PL_LIST "${CMAKE_CURRENT_LIST_DIR}/prolog/*.pl")
# file(GLOB_RECURSE HEADER_LIST "${CMAKE_CURRENT_LIST_DIR}/include/my_lib/*.hpp")

# add_executable(${PROJECT_NAME} ${SOURCE_LIST} ${PL_LIST} ${HEADER_LIST})

# target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#     $<INSTALL_INTERFACE:include>
#     PRIVATE
#     src)
# target_link_libraries(${PROJECT_NAME} PUBLIC ${SWIPL_LIBRARIES} ${CMAKE_DL_LIBS})
