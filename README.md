# LoiterBot

Software for a ROS2-based robot that seeks and approaches the first obstacle it sees, and then wanders around nearby (not too far from it, but not too close either).

## Objective

I used this project to experiment with design approaches for finite state machine (FSM) based robot software. The navigation algorithm is crude. (Improving the algorithm is an exercise for another day.)

## Design

I started with an FSM implemented with a switch statement, but ended up replacing that approach with a design based on the Gang of Four (GoF: the book "Design Patterns" by Gamma, Helm, Johnson, Vlissides) State Pattern. I found the GoF State Pattern was a natural fit with thorough unit tests. It provided (actuall, demanded) a clear contract for each state handler, and isolated them from each other. It made it easy to debug each state handler in the IDE before testing them working together in the simulator.

## The robot

The robot is simulated (I used gazebo). It provides lidar readings by publishing sensor_msgs::msg::LaserScan messages, and accepts motion control commands by listening for geometry_msgs::msg::Twist messages.

The gazebo world I used can be started by running:
./scripts/start.sh
