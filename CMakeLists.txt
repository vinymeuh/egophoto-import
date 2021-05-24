cmake_minimum_required(VERSION 3.18)

project(egophoto-import LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick QuickControls2)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PROJECT_SOURCES
    src/main.cpp
    resources.qrc
)

qt_add_executable(
    ${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE Qt6::Core Qt6::Quick Qt6::QuickControls2
)
