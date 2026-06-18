## memo

ros2とは
→OSとアプリ(Autowareなど)の間のミドルウェア

- node
単純なlinuxプログラムの個々
センサから数値を読み取る、モータの回転数を制御する　など
Lidarを用いた自己位置推定では、センサドライバ→センサデータ処理→自己位置推定　の３つのノードが動作する

- package
アプリケーションの構成単位
複数のnodeによりpackage(アプリケーション)が構成される

- ROS master
各nodeを管理し、node間を接続するサーバ
rescore子安堵によってROS masterを起動する

- Message
node間でやりとりされる情報
一方向のTopicと双方向のServiceがある

- Topic
Node間でMessageをやりとりするための名前付きパス

- rosrun
ROSにおける実行コマンド
`rosrun a_package b_node`など

- roslaunch
複数nodeを実行するコマンド

- bag
ROSで送受信されるMessageを保存するファイル形式

## build system
コンパイルやライブラリのリンクなどをまとめて実行する
ROS2ではcolonを使う

ament：各パッケージをどうビルドするか定義する仕組み
colon：複数のpackageをまとめてbuildするツール

## ワークスペース作成 → パッケージ作成 → ノード作成 → ビルド → 実行
1. ワークスペース作成
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws
tree -L 2 # ディレクトリ構成を深さ2階層まで表示する

2. amentを使ってpackageを作成する
cd ~/ros2_ws/src
'# package名はlearning_ros2、ament_pythonのビルドシステムを使う
ros2 pkg create --build-type ament_python my_learning_ros2

```
my_learning_ros2
├── package.xml # packageの依存関係
├── setup.py # build時に利用する設定ファイル
├── setup.cfg # python packageをどうインすｔ－るするか定義
├── resource
│   └── my_learning_ros2
└── my_learning_ros2
    └── __init__.py
```

3. node作成
cd ~/ros2_ws/src/my_learning_ros2/src
touch hello_node.py

```
import rclpy
from rclpy.node import Node


class HelloNode(Node):

    def __init__(self):
        super().__init__('hello_node')
        self.get_logger().info('Hello ROS2!')


def main(args=None):
    rclpy.init(args=args)

    node = HelloNode()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
```

4. setup.py登録
hello_node->my_learning_ros2->hello_node.py->main()の対応関係を指定　
```
entry_points={
    'console_scripts': [
        'hello_node = my_learning_ros2.hello_node:main',
    ],
},
```

5. build
cd ~/ros_ws
colon build

下記ディレクトリができる
```
ros2_ws
├── build/
├── install/
├── log/
└── src/
````

6. 実行
# 現在のシェルに設定ファイルを読み込む　
source install/setup.bash
# my_learning_ros2 packageのsetup.pyにあるhello_nodeの実行ファイルを実行する
ros2 run my_learning_ros2 hello_node


