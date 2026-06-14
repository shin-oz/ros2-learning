# ROS2 Learning Environment

## Objective
To learn ROS2 fundamentals and autonomous driving software architecture through hands-on development using reproducible Linux/Docker environments.

## Environment
- Windows 11 + WSL2 (Ubuntu)
- Docker / Docker Compose
- ROS2 Humble

## Learning Focus
- ROS2 communication architecture
- QoS behavior and DDS-based networking
- Docker-based ROS2 development workflow
- Inter-container communication and debugging
- Foundations for Autoware and autonomous driving software integration

## Current Progress('26/6/14)
- ROS2 publisher/subscriber tutorial
- Service / Action tutorial
- Launch system basics
- GitHub-based environment management

## Future Plans
- Study Autoware architecture
- Implement custom ROS2 nodes
- Learn Linux and middleware concepts
- Explore autonomous driving software integration workflows

## directory structure
```
ros2-learning/
├── docker/
│   ├── Dockerfile
│   └── compose.yaml
├── tutorials/
│   ├── pub_sub/
│   ├── service/
│   └── action/
├── notes/
│   ├── ros2_network.md
│   ├── qos.md
│   └── docker_ros.md
├── screenshots/
├── README.md
└── .github/
```