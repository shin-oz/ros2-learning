# subscriber node

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Listener(Node):
  def __init__(self):
    super().__init__('listener')
    # Q: なぜ publisher_ の末尾に _ を付ける? → ROS 2公式チュートリアルの慣例(親クラスの属性名とかぶらないように)
    # create_publisher / create_subscription は rclpy の Node クラスのメソッド
    # publisherとlistenerでtopic名とメッセージ型が一致すれば自動的に繋がる
    # Node.create_subscription()methodはmsg型,topic名,callback関数,Qos設定
    # subscriber側はいつメッセージ送るかはわからないので受信したらcallback関数を実行できるようにする必要あり
    self.subscription = self.create_subscription(
      String,
      'chatter',
      self.listener_callback,
      10
    )

  def listener_callback(self, msg):
      self.get_logger().info(f'I heard: "{msg.data}"')

def main(args=None):
  # main()で受け取ったargsをrclpy.init()に渡す
  rclpy.init(args=args)
  node = Listener()

  try:
    rclpy.spin(node)
  except KeyboardInterrupt:
    pass

  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()