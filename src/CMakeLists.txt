
set(CD_L ${CMAKE_CURRENT_SOURCE_DIR})

if (DEFINED TEST)

    set(SOURCE 
        ${SOURCE}
        ${CD_L}/test.cpp
        PARENT_SCOPE
    )

else()

    #add_subdirectory(Window)

    set(SOURCE 
        ${SOURCE}
        ${CD_L}/main.cpp
        PARENT_SCOPE
    )

endif()
