# subscriber node

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Listner(Node):
  def __init__(self):
    super().__init__('listner')
    # ???なんで_必要?
    # create_publisherはrclpyのmethod?
    # publisherとlistnerでtopic名とメッセージ型が一致すれば自動的に繋がる
    # Node.create_subscription()methodはmsg型,topic名,callback関数,Qos設定
    # subscriber側はいつメッセージ送るかはわからないので受信したらcallback関数を実行できるようにする必要あり
    self.subscription = self.create_subscription(
      String,
      'chatter',
      self.listner_callback,
      10
    )

  def listner_callback(self, msg):
      self.get_logger().info(f'I heard: "{msg.data}"')

def main(args=None):
  # main()で受け取ったargsをrxpy.init()に渡す
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