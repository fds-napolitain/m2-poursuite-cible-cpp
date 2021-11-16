cmake_minimum_required(VERSION 3.20)
project(TargetTracking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        )
find_package(OpenCV REQUIRED)


add_executable(TargetTracking main.cpp view/MainWindow.cpp view/MainWindow.hpp view/ImageWidget.cpp view/ImageWidget.hpp model/Image.cpp model/Image.hpp view/ImageStreamWidget.cpp view/ImageStreamWidget.hpp view/WorkerThread.cpp view/WorkerThread.hpp)
target_link_libraries(TargetTracking
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${OpenCV_LIBS}
        )

set_target_properties(TargetTracking PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE FALSE
        )

