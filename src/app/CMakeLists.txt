qt_add_executable(helloqt
    main.cpp
)

target_link_libraries(helloqt PRIVATE Qt6::Widgets Qt6::Gui)

set_target_properties(helloqt PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)