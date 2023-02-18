ament_add_gtest(laser_test
        laser/laser_test.cpp
        ../include/loiterbot/laser/laser_analyzer.hpp ../src/laser/laser_analyzer.cpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.hpp ../src/obstacle/nearest_sighting.cpp)
ament_add_gtest(velocity_calculator_test
        velocity/velocity_calculator_test.cpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.hpp ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp)
ament_add_gtest(state_handler_search_test
        statehandler/state_handler_search_test.cpp
        ../src/fsm/statehandler/state_handler_search.cpp ../include/loiterbot/fsm/statehandler/state_handler_search.hpp
        ../src/history.cpp ../include/loiterbot/history.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.hpp ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp
        ../src/action.cpp ../include/loiterbot/action.hpp)
ament_add_gtest(state_handler_near_test
        statehandler/state_handler_near_test.cpp
        ../src/fsm/statehandler/state_handler_near.cpp ../include/loiterbot/fsm/statehandler/state_handler_near.hpp
        ../src/history.cpp ../include/loiterbot/history.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.hpp ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp
        ../src/action.cpp ../include/loiterbot/action.hpp)
ament_add_gtest(state_handler_too_near_test
        statehandler/state_handler_too_near_test.cpp
        ../src/fsm/statehandler/state_handler_too_near.cpp ../include/loiterbot/fsm/statehandler/state_handler_too_near.hpp
        ../src/history.cpp ../include/loiterbot/history.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.hpp ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp
        ../src/action.cpp ../include/loiterbot/action.hpp)

ament_add_gtest(vff_vector_calculator_unittest
        velocity/vff/vff_calculator_test.cpp
        ../include/loiterbot/velocity/vff/vector_force_field_calculator.hpp
        ../src/velocity/vff/vector_force_field_calculator.cpp
        ../include/loiterbot/vector/vector_by_standard_position.hpp
        ../src/vector/vector_by_standard_position.cpp)

ament_add_gtest(vector_converter_unittest
        velocity/vff/vector_converter_test.cpp
        ../include/loiterbot/vector/vector_converter.hpp
        ../src/vector/vector_converter.cpp
        ../include/loiterbot/vector/vector_by_magnitude_angle.hpp
        ../src/vector/vector_by_magnitude_angle.cpp
        ../include/loiterbot/vector/vector_by_standard_position.hpp
        ../src/vector/vector_by_standard_position.cpp)

ament_target_dependencies(laser_test ${dependencies})
ament_target_dependencies(velocity_calculator_test ${dependencies})
ament_target_dependencies(state_handler_search_test ${dependencies})
ament_target_dependencies(state_handler_near_test ${dependencies})
ament_target_dependencies(state_handler_too_near_test ${dependencies})
ament_target_dependencies(vff_vector_calculator_unittest ${dependencies})
ament_target_dependencies(vector_converter_unittest ${dependencies})
