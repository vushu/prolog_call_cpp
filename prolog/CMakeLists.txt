cmake_minimum_required(VERSION 3.20...3.28)
project(prolog_main)

include(FindPkgConfig)
pkg_check_modules(SWIPL REQUIRED swipl)
include_directories(${SWIPL_INCLUDE_DIRS})
link_directories(${SWIPL_LIBRARY_DIRS})

# Find SWI-Prolog
find_program(SWIPL_EXECUTABLE swipl REQUIRED)
if (NOT SWIPL_EXECUTABLE)
    message(FATAL_ERROR "SWI-Prolog not found!")
endif()


# Output the SWI-Prolog version
execute_process(
    COMMAND ${SWIPL_EXECUTABLE} --version
    OUTPUT_VARIABLE SWIPL_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
message(STATUS "Found SWI-Prolog: ${SWIPL_VERSION}")

# Add Prolog files (optional, for organization)
set(PROLOG_FILES main.pl)

add_library(${PROJECT_NAME} SHARED foolib.cpp)
# Add the C++ executable
# add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# Optionally, run Prolog file as part of the build
make_directory("${CMAKE_SOURCE_DIR}/bin")

add_custom_target(
    run_prolog ALL
    COMMAND ${SWIPL_EXECUTABLE} -o "${CMAKE_SOURCE_DIR}/bin/main" -g main -c ${CMAKE_CURRENT_LIST_DIR}/main.pl
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running Prolog file"
)



# Copy the library over to bin 
add_custom_target(
    copy_so ALL
    COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_BINARY_DIR}/prolog/libprolog_main.so"
            "${CMAKE_SOURCE_DIR}/bin/foolib.so"

)
# configure_file("${CMAKE_BINARY_DIR}/prolog/libprolog_main.so" "${CMAKE_SOURCE_DIR}/bin/foo.so" COPYONLY)

target_link_libraries(${PROJECT_NAME} PUBLIC ${SWIPL_LIBRARIES})
# Add dependencies
