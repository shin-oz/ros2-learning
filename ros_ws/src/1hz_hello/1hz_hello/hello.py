import rclpy
from rclpy.node import Node

class Hello1hz(Node):
  def __init__(self):
    super().__init__('hello1hz')

    self.count = 0
    self.timer = self.create_timer(1.0, self.timer_callback)

  # 単純なwhile rclpy.ok()では中断されるまでrclpy.spin(node)が呼ばれずtimerにならなかった
  # rclpy.spin(node)はnodeを実行し続け登録されているcallbackを実際に呼び出すevent loop
  def timer_callback(self):
    self.get_logger().info(f"Hello world {self.count}")
    self.count += 1

def main(args=None):
  rclpy.init(args=args)
  node = Hello1hz()

  try:
    rclpy.spin(node)
  except KeyboardInterrupt:
    pass
  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()