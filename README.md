# LoiterBot

Software for a ROS2-based robot that seeks and approaches the first obstacle it sees, and then wanders around nearby (not too far from it, but not too close either).

## Objective

I used this project to experiment with design approaches for finite state machine (FSM) based robot software. The navigation algorithm is crude. (Improving the algorithm is an exercise for another day.)

## Design

I started down the path of implementing the FSM with a switch statement, but ended up ditching that approach in favor of a design based on the Gang of Four (GoF: the book "Design Patterns" by Gamma, Helm, Johnson, Vlissides) State Pattern. In my mind the GoF State Pattern provided a few significant advantages over the switch statement approach:

* It allows (actually, demands) that the code to handle each state is separated into its own class.
* It provides (actually, demands) a clear contract for each state handler class.

Having the FSM split into a set of unit testable classes made it easy to develop and debug each state handler in isolation (with all the benefits of the IDE debugger) before running everything together in the simulator.

## The robot

The robot is simulated (I used gazebo). It provides lidar readings by publishing sensor_msgs::msg::LaserScan messages, and accepts motion control commands by listening for geometry_msgs::msg::Twist messages.

The gazebo world I used can be started by running:
./scripts/start.sh
