import rclpy # ROS2の機能をpythonから使えるようにする
from rclpy.node import Node # Nodeの基礎となるclassをimport

# Nodeクラスを継承したHelloNodeクラスを作成
class HelloNode(Node):
    # HelloNodeクラスのinit
    def __init__(self):
        
        # rclpy.node.Nodeクラスをhello_nodeとして__init__メソッドを使う
        # ros2で使えるようにするために必要
        # super->pythonの組み込み関数で親クラスを参照
        super().__init__('hello_node')
        # get_logger()はloggerを取得
        # logをinfoレベルとして登録
        # logのレベルは他にdebug/warn/eror/fatalがある
        self.get_logger().info('Hello ROS2!')

def main(args=None):
    # ROS2のシステム全体を使えるように初期化
    # HelloNodeを作るなどの前提条件として必要
    rclpy.init(args=args)

    # nodeインスタンスを作成
    node = HelloNode()

    # nodeインスタンスを実行し続ける
    rclpy.spin(node)

    # ctrl-Cなどでspinを終えたあとにnodeを破棄する
    # ROS2では長時間nodeを動き続けるなどあるらしく、node破棄を明示しないとゾンビプロセスとして残ってしまう
    node.destroy_node()
    rclpy.shutdown()

# python実行時に__name__という変数が自動作成
# 直接script実行した場合は__main__になる
# 直接実行した時だけmain()が実行されるようにする
if __name__ == '__main__':
    main()