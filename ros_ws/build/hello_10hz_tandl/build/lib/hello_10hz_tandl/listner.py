# subscriber node

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Listner(Node):
  def __init__(self):
    super().__init__('listner')
    # ???なんで_必要?
    # create_publisherはrclpyのmethod?
    self.subscription = self.create_subscription(
      String,
      'chatter',
      self.listner_callback, # これなんだっけ？
      10
    )

  def listner_callback(self, msg):
      self.get_logger().info(f'I heard: "{msg.data}"')

def main(args=None):
  # なんでargs=argsなんだっけ？
  rclpy.init(args=args)
  node = Listner()

  try:
    rclpy.spin(node)
  except KeyboardInterrupt:
    pass

  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()