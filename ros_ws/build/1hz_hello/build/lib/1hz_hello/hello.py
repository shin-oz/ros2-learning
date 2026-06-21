import rclpy
from rclpy.node import Node

class Hello1hz(Node):
  def __init__(self):
    super().__init__('hello1hz')

  def run(self):
    # create_rate()はnode classのmethod
    # 1hzで設定する
    rate = self.create_rate(1)

    count = 0
    while rclpy.ok(): #rclpy.ok() ROSが正常かどうか確認->True/Falseが戻り値
      self.get_logger().info(f'Hello world {count}')
      count += 1
      rate.sleep() #rateが経過するまで待機

def main(args=None):
  rclpy.init(args=args)

  node = Hello1hz()

  try:
    node.run()
  except KeyboardInterrupt: # KeybordInterrupt: pythonの組み込みexception class
    pass

  node.destroy_node()
  rclpy.shutdown()

if __name__ == '__main__':
  main()