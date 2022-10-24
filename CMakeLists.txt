cmake_minimum_required(VERSION 3.0.0)

project(word_converter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(CTest)
enable_testing()

if (DEFINED TEST)

    set(TEST_DIRECTORIES "")
    set(TEST_LINKED "")

    add_subdirectory(libs)

    include_directories(
        include
        ${TEST_DIRECTORIES}
    )

    add_subdirectory(src)

    add_executable(Test ${SOURCE})

    target_link_libraries(
        Test
        ${TEST_LINKED}
    )

else()

    add_subdirectory(libs)

    include_directories(
        include
        ${INCLUDE_LIBS}
    )

    add_subdirectory(src)

    add_executable(${PROJECT_NAME} ${SOURCE})

    target_link_libraries(
        ${PROJECT_NAME}
        ${LINKED_LIBS}
    )

    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)

endif()
