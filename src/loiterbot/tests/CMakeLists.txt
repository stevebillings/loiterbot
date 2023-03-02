ament_add_gtest(laser_test
        laser/laser_test.cpp
        test_constants.hpp
        ../include/loiterbot/laser/laser_analyzer.hpp ../src/laser/laser_analyzer.cpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/vector/vector_by_magnitude_angle.hpp ../src/vector/vector_by_magnitude_angle.cpp)
ament_add_gtest(velocity_calculator_test
        velocity/velocity_calculator_test.cpp
        test_constants.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp)

ament_add_gtest(state_handler_go_test
        statehandler/state_handler_go_test.cpp
        test_constants.hpp
        ../src/fsm/statehandler/state_handler_go.cpp ../include/loiterbot/fsm/statehandler/state_handler_go.hpp
        ../src/history.cpp ../include/loiterbot/history.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp
        ../include/loiterbot/velocity/vff/vector_force_field_calculator.hpp ../src/velocity/vff/vector_force_field_calculator.cpp
        ../include/loiterbot/vector/vector_converter.hpp ../src/vector/vector_converter.cpp
        ../include/loiterbot/vector/vector_by_magnitude_angle.hpp ../src/vector/vector_by_magnitude_angle.cpp
        ../include/loiterbot/vector/vector_by_standard_position.hpp ../src/vector/vector_by_standard_position.cpp
        ../src/action.cpp ../include/loiterbot/action.hpp)
ament_add_gtest(state_handler_blocked_test
        statehandler/state_handler_blocked_test.cpp
        test_constants.hpp
        ../src/fsm/statehandler/state_handler_blocked.cpp ../include/loiterbot/fsm/statehandler/state_handler_blocked.hpp
        ../src/history.cpp ../include/loiterbot/history.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp
        ../src/action.cpp ../include/loiterbot/action.hpp)

ament_add_gtest(vector_force_field_calculator_test
        velocity/vff/vector_force_field_calculator_test.cpp
        test_constants.hpp
        ../include/loiterbot/velocity/vff/vector_force_field_calculator.hpp
        ../src/velocity/vff/vector_force_field_calculator.cpp
        ../include/loiterbot/vector/vector_by_standard_position.hpp
        ../src/vector/vector_by_standard_position.cpp)

ament_add_gtest(vector_converter_test
        velocity/vff/vector_converter_test.cpp
        test_constants.hpp
        ../include/loiterbot/vector/vector_converter.hpp
        ../src/vector/vector_converter.cpp
        ../include/loiterbot/vector/vector_by_magnitude_angle.hpp
        ../src/vector/vector_by_magnitude_angle.cpp
        ../include/loiterbot/vector/vector_by_standard_position.hpp
        ../src/vector/vector_by_standard_position.cpp)

ament_target_dependencies(laser_test ${dependencies})
ament_target_dependencies(velocity_calculator_test ${dependencies})
ament_target_dependencies(state_handler_go_test ${dependencies})
ament_target_dependencies(state_handler_blocked_test ${dependencies})
ament_target_dependencies(vector_force_field_calculator_test ${dependencies})
ament_target_dependencies(vector_converter_test ${dependencies})
