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
        loiterbot/statehandler/state_handler_search_test.cpp
        ../src/fsm/statehandler/state_handler_search.cpp ../include/loiterbot/fsm/statehandler/state_handler_search.hpp
        ../src/history.cpp ../include/loiterbot/history.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.hpp ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp
        ../src/action.cpp ../include/loiterbot/action.hpp)
ament_add_gtest(state_handler_near_test
        loiterbot/statehandler/state_handler_near_test.cpp
        ../src/fsm/statehandler/state_handler_near.cpp ../include/loiterbot/fsm/statehandler/state_handler_near.hpp
        ../src/history.cpp ../include/loiterbot/history.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.hpp ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp
        ../src/action.cpp ../include/loiterbot/action.hpp)
ament_add_gtest(state_handler_too_near_test
        loiterbot/statehandler/state_handler_too_near_test.cpp
        ../src/fsm/statehandler/state_handler_too_near.cpp ../include/loiterbot/fsm/statehandler/state_handler_too_near.hpp
        ../src/history.cpp ../include/loiterbot/history.hpp
        ../include/loiterbot/laser/laser_characteristics.hpp ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.hpp ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.hpp ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.hpp ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.hpp ../src/velocity/velocity_calculator.cpp
        ../src/action.cpp ../include/loiterbot/action.hpp)

ament_add_gtest(vff_unittest
        velocity/vff/vff_unittest.cpp
        ../include/loiterbot/velocity/vff/vff.hpp
        ../src/velocity/vff/vff.cpp)

ament_add_gtest(vector_unittest
        velocity/vff/vector_unittest.cpp
        ../include/loiterbot/velocity/vff/vector.hpp
        ../src/velocity/vff/vector.cpp)

ament_target_dependencies(laser_test ${dependencies})
ament_target_dependencies(velocity_calculator_test ${dependencies})
ament_target_dependencies(state_handler_search_test ${dependencies})
ament_target_dependencies(state_handler_near_test ${dependencies})
ament_target_dependencies(state_handler_too_near_test ${dependencies})
ament_target_dependencies(vff_unittest ${dependencies})
ament_target_dependencies(vector_unittest ${dependencies})
