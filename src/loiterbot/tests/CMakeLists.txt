ament_add_gtest(laser_test
        laser/laser_test.cpp
        ../src/laser/laser_analyzer.h ../src/laser/laser_analyzer.cpp
        ../src/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../src/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../src/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp)
ament_add_gtest(velocity_calculator_test
        velocity/velocity_calculator_test.cpp
        ../src/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../src/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../src/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp
        ../src/velocity/velocity.h ../src/velocity/velocity.cpp
        ../src/velocity/velocity_calculator.h ../src/velocity/velocity_calculator.cpp)
ament_add_gtest(state_search_test
        loiterbot/state/state_search_test.cpp
        ../src/loiterbot/state/state_handler_search.cpp ../src/loiterbot/state/state_handler_search.h
        ../src/history/history.cpp ../src/history/history.h
        ../src/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../src/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../src/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp
        ../src/velocity/velocity.h ../src/velocity/velocity.cpp
        ../src/velocity/velocity_calculator.h ../src/velocity/velocity_calculator.cpp
        ../src/loiterbot/action.cpp ../src/loiterbot/action.h)
ament_add_gtest(state_near_test
        loiterbot/state/state_near_test.cpp
        ../src/loiterbot/state/state_handler_near.cpp ../src/loiterbot/state/state_handler_near.h
        ../src/history/history.cpp ../src/history/history.h
        ../src/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../src/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../src/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp
        ../src/velocity/velocity.h ../src/velocity/velocity.cpp
        ../src/velocity/velocity_calculator.h ../src/velocity/velocity_calculator.cpp
        ../src/loiterbot/action.cpp ../src/loiterbot/action.h)
ament_add_gtest(state_too_near_test
        loiterbot/state/state_too_near_test.cpp
        ../src/loiterbot/state/state_handler_too_near.cpp ../src/loiterbot/state/state_handler_too_near.h
        ../src/history/history.cpp ../src/history/history.h
        ../src/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../src/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../src/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp
        ../src/velocity/velocity.h ../src/velocity/velocity.cpp
        ../src/velocity/velocity_calculator.h ../src/velocity/velocity_calculator.cpp
        ../src/loiterbot/action.cpp ../src/loiterbot/action.h)
#ament_target_dependencies(laser_test ${dependencies})
#ament_target_dependencies(velocity_calculator_test ${dependencies})
