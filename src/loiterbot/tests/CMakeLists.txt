ament_add_gtest(laser_test
        laser/laser_test.cpp
        ../include/loiterbot/laser/laser_analyzer.h ../src/laser/laser_analyzer.cpp
        ../include/loiterbot/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp)
ament_add_gtest(velocity_calculator_test
        velocity/velocity_calculator_test.cpp
        ../include/loiterbot/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.h ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.h ../src/velocity/velocity_calculator.cpp)
ament_add_gtest(state_handler_search_test
        loiterbot/statehandler/state_handler_search_test.cpp
        ../src/loiterbot/statehandler/state_handler_search.cpp ../src/loiterbot/statehandler/state_handler_search.h
        ../src/loiterbot/history.cpp ../src/loiterbot/history.h
        ../include/loiterbot/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.h ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.h ../src/velocity/velocity_calculator.cpp
        ../src/loiterbot/action.cpp ../src/loiterbot/action.h)
ament_add_gtest(state_handler_near_test
        loiterbot/statehandler/state_handler_near_test.cpp
        ../src/loiterbot/statehandler/state_handler_near.cpp ../src/loiterbot/statehandler/state_handler_near.h
        ../src/loiterbot/history.cpp ../src/loiterbot/history.h
        ../include/loiterbot/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.h ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.h ../src/velocity/velocity_calculator.cpp
        ../src/loiterbot/action.cpp ../src/loiterbot/action.h)
ament_add_gtest(state_handler_too_near_test
        loiterbot/statehandler/state_handler_too_near_test.cpp
        ../src/loiterbot/statehandler/state_handler_too_near.cpp ../src/loiterbot/statehandler/state_handler_too_near.h
        ../src/loiterbot/history.cpp ../src/loiterbot/history.h
        ../include/loiterbot/laser/laser_characteristics.h ../src/laser/laser_characteristics.cpp
        ../include/loiterbot/laser/laser_analysis.h ../src/laser/laser_analysis.cpp
        ../include/loiterbot/obstacle/nearest_sighting.h ../src/obstacle/nearest_sighting.cpp
        ../include/loiterbot/velocity/velocity.h ../src/velocity/velocity.cpp
        ../include/loiterbot/velocity/velocity_calculator.h ../src/velocity/velocity_calculator.cpp
        ../src/loiterbot/action.cpp ../src/loiterbot/action.h)

ament_target_dependencies(laser_test ${dependencies})
ament_target_dependencies(velocity_calculator_test ${dependencies})
ament_target_dependencies(state_handler_search_test ${dependencies})
ament_target_dependencies(state_handler_near_test ${dependencies})
ament_target_dependencies(state_handler_too_near_test ${dependencies})
