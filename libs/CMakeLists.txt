################# LIBRARIES #################
# Maybe do shared libraries #
################# INIT LIBRARIES #################

##### LIST #####

set(LIST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/list)

add_library(LIST STATIC)

target_sources(LIST
    PRIVATE
        ${LIST_DIR}/src/list.cpp
        ${LIST_DIR}/src/string_list.cpp
)

target_include_directories(LIST
    PUBLIC
        ${LIST_DIR}/include
)

## Set variables to project ##

set(INCLUDE_LIBS
    ${INCLUDE_LIBS}
    LIST
)

set(LINKED_LIBS
    ${LINKED_LIBS}
    LIST
)

if (DEFINED TEST_LIST)

    set(TEST_DIRECTORIES 
        ${TEST_DIRECTORIES}
        LIST
    )

    set(TEST_LINKED 
        ${TEST_LINKED}
        LIST
    )

endif()

## end setting variables to project ##

##### END LIST #####
##### UTILS #####

set(UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/utils)

add_library(UTILS STATIC)

include_directories(
    UTILS
    ${UTILS_DIR}/include
)

target_include_directories(UTILS
    PUBLIC
        ${UTILS_DIR}/include
        ${THREAD_DIR}/include
        ${LIST_DIR}/include
)

target_sources(UTILS
    PRIVATE
        ${UTILS_DIR}/src/str.cpp
        ${UTILS_DIR}/src/date_time.cpp
        ${UTILS_DIR}/src/file.cpp
)

target_link_libraries(
    UTILS
    LIST
)

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/logs)

## Set variables to project ##

set(INCLUDE_LIBS
    ${INCLUDE_LIBS}
    UTILS
)

set(LINKED_LIBS
    ${LINKED_LIBS}
    UTILS
)

if (DEFINED TEST_UTILS)

    set(TEST_DIRECTORIES 
        ${TEST_DIRECTORIES}
        UTILS
    )

    set(TEST_LINKED
        ${TEST_LINKED}
        UTILS
    )

endif()

## end setting variables to project ##

##### END UTILS #####

## set variables to general project ##

set(INCLUDE_LIBS
    ${INCLUDE_LIBS}
    PARENT_SCOPE
)

set(LINKED_LIBS
    ${LINKED_LIBS}
    PARENT_SCOPE
)

set(TEST_DIRECTORIES 
    ${TEST_DIRECTORIES}
    PARENT_SCOPE
)

set(TEST_LINKED
    ${TEST_LINKED}
    PARENT_SCOPE
)

## end setting variables to general project ##
