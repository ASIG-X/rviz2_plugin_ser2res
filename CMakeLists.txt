cmake_minimum_required(VERSION 3.8)
project(rviz2_plugin_ser2res)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3 -Wall -g")

find_package(ament_cmake REQUIRED)
find_package(ament_lint_auto REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rviz_common REQUIRED)
find_package(pluginlib REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)

add_library(${PROJECT_NAME} SHARED src/Service2Reset.cpp)

ament_lint_auto_find_test_dependencies()

ament_target_dependencies(${PROJECT_NAME}
        rclcpp
        std_srvs
        rviz_common)

target_include_directories(${PROJECT_NAME} PUBLIC ${Qt5Widgets_INCLUDE_DIRS})

pluginlib_export_plugin_description_file(rviz_common description.xml)

install(TARGETS ${PROJECT_NAME}
        DESTINATION lib/${PROJECT_NAME})

ament_export_dependencies(rclcpp std_srvs rviz_common)

ament_package()
