# ROS2 Learning Log

Hands-on learning log toward a career in autonomous driving software integration.
**Work in progress** — updated as I learn.

## Environment
- Windows 11 + WSL2 (Ubuntu 24.04)
- ROS2 Jazzy
- Docker (osrf/ros:jazzy-desktop)

## Learning Focus
- ROS2 communication architecture
- QoS behavior and DDS-based networking
- Docker-based ROS2 development workflow
- Foundations for Autoware and autonomous driving software integration

## Repository Structure
```
ros2-learning/
├── ros_ws/src/              # ROS2 packages (rclpy)
│   ├── my_learning_ros2/    # first node
│   ├── 1hz_hello/           # 1 Hz timer node
│   └── hello_10hz_tandl/    # 10 Hz talker / listener
├── CPP/                     # C fundamentals (pointers, multi-file build, file I/O)
├── notes/                   # learning notes (ROS2, Docker, Linux, C)
└── screenshots/             # execution results
```

## Progress (updated 2026/10/09)
- [x] ROS2 environment setup on WSL2 / Docker
- [x] rclpy publisher / subscriber with timer
- [x] C fundamentals: pointers, multi-file build with headers, file I/O
- [ ] C++ fundamentals(in progress)
- [ ] Port talker / listener from rclpy to rclcpp
- [ ] Dockerfile / compose for a reproducible environment
- [ ] Autoware architecture study
