qt_add_executable(helloqt
    main.cpp
)

target_link_libraries(helloqt PRIVATE Qt6::Widgets Qt6::Gui)

set_target_properties(helloqt PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


if(NOT USE_STATIC_LIBS)



    
    
    add_custom_command(TARGET helloqt POST_BUILD
        COMMAND ${WINDEPLOYQT}  $<TARGET_FILE:helloqt>
    )
    

    
endif()