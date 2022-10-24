
set(CD_L ${CMAKE_CURRENT_SOURCE_DIR})

if (DEFINED TEST)

    set(SOURCE 
        ${SOURCE}
        ${CD_L}/test.cpp
        PARENT_SCOPE
    )

else()

    set(SOURCE 
        ${SOURCE}
        ${CD_L}/main.cpp
        ${CD_L}/number.cpp
        PARENT_SCOPE
    )

endif()
