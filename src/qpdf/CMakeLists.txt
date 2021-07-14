project(qpdf)


find_package(Qt5 COMPONENTS Core Widgets Network)
include_directories(${Qt5Core_PRIVATE_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Widgets_PRIVATE_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS})
include_directories(../3rdparty/pdfium)
include_directories(include)

file(GLOB_RECURSE SRCS *.h *.cpp *.ui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
    

add_definitions(-DQT_BUILD_PDF_LIB)
add_library(${PROJECT_NAME} SHARED ${SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE pdfium Qt::Core Qt::Widgets Qt::Network)

