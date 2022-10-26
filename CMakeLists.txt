cmake_minimum_required(VERSION 3.16)

project(Abschluss_001 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)



qt_add_executable(appAbschluss_001
    main.cpp
    logik.h logik.cpp
    auto.h auto.cpp
    gas.h gas.cpp
    speed.h speed.cpp
    drehzahl.h drehzahl.cpp
    bremse.h bremse.cpp
    tempo.h tempo.cpp
    kilometerstand.h kilometerstand.cpp
    res.qrc
)

qt_add_qml_module(appAbschluss_001
    URI Abschluss_001
    VERSION 1.0
    QML_FILES main.qml 

    RESOURCES
        bkgr_001_ab_728.png
        RueckBild_02.jpg


)

set_target_properties(appAbschluss_001 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appAbschluss_001 PRIVATE Qt6::Quick)
target_link_libraries(appAbschluss_001 PRIVATE Qt6::Core)
target_link_libraries(appAbschluss_001 PRIVATE Qt6::Gui)

install(TARGETS appAbschluss_001
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
