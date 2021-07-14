project(test_pdfviewer)

find_package(Qt5 COMPONENTS Core Widgets)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src/qpdf/include)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
    
file(GLOB SRCS pdfviewer/*.h pdfviewer/*.cpp pdfviewer/*.ui)
file(GLOB RCSS pdfviewer/*.qrc)

add_executable(${PROJECT_NAME} ${SRCS} ${RCSS})
target_link_libraries(${PROJECT_NAME} PRIVATE qpdf pdfium Qt::Core Qt::Widgets)
