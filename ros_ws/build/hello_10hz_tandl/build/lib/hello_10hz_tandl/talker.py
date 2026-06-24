# publisher node

import rclpy # ros2機能をpythonで使えるようにする　
from rclpy.node import Node # nodeの基礎となるclass
# ros2のtopic通信でString型メッセージを取り扱うために必要　
## publisherとsubscriberで同じメッセージ型にする必要あり
from std_msgs.msg import String

class Talker(Node):
  def __init__(self):
    # 親クラスをもとにtalkerとしてROS2で使えるように宣言
    super().__init__('talker')
    # publisherとlistnerでtopic名とメッセージ型が一致すれば自動的に繋がる
    # ↑はDDS ROS masterとは異なる
    # Node.create_publisher()methodはmsg型,topic名,Qos設定
    # Qos設定はque sizeを指定
    # member変数かつ予約語と衝突しないように末尾に_をつけた
    self.publisher_ = self.create_publisher(String, 'chatter', 10)
    self.count = 0
    # Node.create_timer()methodは指定した感覚ごとにcallback関数を実行する
    self.timer = self.create_timer(1.0, self.timer_callback)

  def timer_callback(self):
    # topic通信が成立するようにString型で統一
    msg = String()
    # Stringはオブジェクトのためフィールド(String型の場合はdataのみ)が必要　
    msg.data = f'Hello world {self.count}'
    # chatter topicにpublish
    self.publisher_.publish(msg)
    self.get_logger().info(f'Publishing: "{msg.data}"')
    self.count += 1

def main(args=None):
  # main()で受け取ったargsをrxpy.init()に渡す
  rclpy.init(args=args)
  node = Talker()

  try:
    rclpy.spin(node)
  except KeyboardInterrupt:
    pass
  
  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
    main()
