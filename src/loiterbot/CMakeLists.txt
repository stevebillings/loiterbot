cmake_minimum_required(VERSION 3.8)
project(loiterbot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

add_executable(loiterbot
        src/loiterbot/loiterbot.cpp
        src/loiterbot/state.h
        src/velocity/velocity.cpp include/loiterbot/velocity/velocity.h
        src/velocity/velocity_calculator.cpp include/loiterbot/velocity/velocity_calculator.h
        src/laser/laser_analyzer.cpp include/loiterbot/laser/laser_analyzer.h
        src/laser/laser_characteristics.cpp include/loiterbot/laser/laser_characteristics.h
        src/laser/laser_analysis.cpp include/loiterbot/laser/laser_analysis.h
        src/obstacle/nearest_sighting.cpp include/loiterbot/obstacle/nearest_sighting.h
        src/loiterbot/statehandler/state_handler.h
        src/loiterbot/statehandler/state_handlers.cpp src/loiterbot/statehandler/state_handlers.h
        src/loiterbot/history.cpp src/loiterbot/history.h
        src/loiterbot/statehandler/state_handler_search.cpp src/loiterbot/statehandler/state_handler_search.h
        src/loiterbot/statehandler/state_handler_near.cpp src/loiterbot/statehandler/state_handler_near.h
        src/loiterbot/statehandler/state_handler_too_near.cpp src/loiterbot/statehandler/state_handler_too_near.h
        src/loiterbot/statehandler/state_handler_error.cpp src/loiterbot/statehandler/state_handler_error.h
        src/loiterbot/action.cpp src/loiterbot/action.h)

set(dependencies
  rclcpp
  sensor_msgs
  geometry_msgs
)

ament_target_dependencies(loiterbot ${dependencies})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

  set(ament_cmake_copyright_FOUND TRUE)

  find_package(ament_cmake_gtest REQUIRED)
  #find_package(ament_cmake_gmock REQUIRED)
  add_subdirectory(tests)
endif()

install(TARGETS
        loiterbot
        DESTINATION lib/${PROJECT_NAME})

ament_export_dependencies(${dependencies})
ament_package()
