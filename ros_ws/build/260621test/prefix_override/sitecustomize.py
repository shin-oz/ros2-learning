import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/shinnosuke/projects/ros2-learning/ros_ws/install/260621test'
