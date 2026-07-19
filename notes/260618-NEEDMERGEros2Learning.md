# 260618-ros2Learning.md

## ros2とは？
目的：ロボット開発を効率化する

ros1との違い
- リアルタイム性向上
- 分散システム対応
- セキュリティ強化
ros2とは
→OSとアプリ(Autowareなど)の間のミドルウェア

## 用語リスト
- package
アプリケーションの構成単位
複数のnodeによりpackage(アプリケーション)が構成される

- ROS master **ROS2で削除された概念**
各nodeを管理し、node間を接続するサーバ
rescoreコマンドによってROS masterを起動する

- Message
node間でやりとりされる情報
一方向のTopicと双方向のServiceがある

- node
単純なlinuxプログラムの個々
センサから数値を読み取る、モータの回転数を制御する　など
例えばLidarを用いた自己位置推定では、センサドライバ→センサデータ処理→自己位置推定の３つのノードが動作する

- Topic通信
Node間でMessageをやりとりするための名前付きパス
Publish/Subscribeモデルで、1対N通信の非同期通信
カメラからの画像生データをTopicとして配信: Publish
車検知のノードでTopicを購読: Subscirbe
歩行者検知のノードでTopicを購読: Subscirbe
メリット：データ型を合わせるだけでNode追加が可能

- Service通信
serviceをrequestするclientとresponseを返すserver間で交わされる1対1通信の同期通信
同期通信なので処理が行われたことをclient側で判別するため処理時間が多く、Autowareではあまり使われないらしい

- rosrun
ROSにおける実行コマンド
`rosrun a_package b_node`など

- roslaunch
複数nodeを実行するコマンド

- rviz2
ROS2の3次元可視化ツールのこと

- rqt
node,topic,messageを扱うGUIツール
階層やグラフ表示することでnodeの新規作成などできる

- bag
ROSで送受信されるMessageを保存するファイル形式

- rosbag
ROS上で動作中のtopicのやり取りデータを保存したbag形式データ
センサデータを記録する際になかった機能を実装できたあと、センサなしで動作確認することができる
`ros2 bag`コマンドを使う？
`ros2 bag record -a`データの保存
`ros2 bag play ###`データの再生

## build
build system: ament ->何をどうbuildするかのルールを定義
build tool: colcon ->buildを実際に実行するツール

### buildの目的
1. パッケージの登録 src directoryにpackageを作り、 ros2 runでpackageを実行した際にsrc directoryを見に行くようになる
2. 依存関係の解決 package.xmlに書いた依存ライブラリを紐づける
3. コンパイル ※C++の場合
4. 環境の統一　install directoryに全packageを集約し、sourceで一括有効化（環境変数を追加する）できるようにする
   1. ros2 runするときは環境変数AMENT_PREFIX_PATHに登録された場所を順番に検索
   2. package.xmlを発見する

## topic communication
under construction

## ros2実行の流れ
### 基本フロー
```
1. packageのひな形を作成する
ros2 pkg create --build-type ament_python my_package

2. コードを編集（src/my_package/my_package）

3. build
cd ~/ros2_ws
colcon build --packages-select my_package

4. 環境を反映
source install/setup.bash

5. 実行
ros2 run my_package my_node
```

### 実際の手順
1. ワークスペース作成
ws ->ros2 packageをまとめて管理・buildするための作業スペース
```
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws
tree -L 2 # ディレクトリ構成を深さ2階層まで表示する
```

2. amentを使ってpackageのtemplateを作成する
ros2では機能ごとにpackageでまとめる
```
cd ~/ros2_ws/src
'# package名はmy_package、ament_pythonのビルドシステムを使う
ros2 pkg create --build-type ament_python my_package
```

```
src/my_package
├── package.xml # packageのpackageの基本情報(名前など)と依存関係(rclpyやstd_msgsなど)依存関係
├── setup.py # build時に利用する設定ファイル python package installのための設定を記述。ros2 runのためのentry pointを記述しておく
├── setup.cfg # python packageをどうインストールするか定義
├── resource
│   └── my_package # buildするとこのファイルがinstall/に登録される。
└── my_package # この中にpackageを作成する
    └── __init__.py # 他ファイルからimportできるようにpythonモジュールであることを宣言、編集不要　
```

3. node作成
```
cd ~/ros2_ws/src/XXX/XXX
touch hello_node.py
```

coding内容
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

4. setup.py追記
hello_node->my_learning_ros2->hello_node.py->main()の対応関係を指定　
```
entry_points={
    'console_scripts': [
        <!-- 実行名 = モジュール名.ファイル名:関数 -->
        'hello_node = my_learning_ros2.hello_node:main',
    ],
},
```

5. build
```
cd ~/ros_ws
# src/を探しにいくため、~/ros2_ws/でbuildすること
colcon build
# --packages-selectでsrc内のファイルを選択可能
# colcon build --packages-select 1hz_hello
```

下記ディレクトリができる
```
ros2_ws
├── build/　中間ファイル（触らなくてよい）
├── install/　実行に使われるファイル群
├── log/　buildのログ
└── src/ 自分で作ったコード
````

6. 実行
```
# 現在のシェルでros2 runするpackageがどこにあるか指定する
source install/setup.bash
# my_learning_ros2 packageのsetup.pyにあるhello_nodeの実行ファイルを実行する
ros2 run my_learning_ros2 hello_node
```

## Turtlesim実行
`source /opt/ros/jazzy/setup.bash`
`ros2 run turtlesim turtlesim_node`
topic例
- /turtle1/cmd_vel 移動指令
- /turtle1/pose 現在状態を取得

turtleを表示するterminalと処理を送るterminalの２つが必要
処理を送る側では`docker exec -it $NAME bash`を実行する

```
<!-- -rはhz指定: 1sに何回コマンドを送るか -->
ros2 topic pub -r 5 /turtle1/cmd_vel geometry_msgs/msg/Twist  "{linear: {x: 1.0}, angular: {z: 0.0}}"
```

## Topic通信とは？
各プログラムの実行単位であるNodeどうしをTopic/Service/Actionで通信する
Topic通信はPub/Subモデル、非同期、一方向通信

- messageを送る
`ros2 topic pub`
`ros2 topic pub /turtle1/cmd_vel geometry_msgs/msg/Twist  "{linear: {x: 2.0}, angular: {z: 1.8}}"`

- topic通信をリアルタイムに観測する
->意図通りの動きか、センサーの値が正しいかの確認に使われる
<!-- 受信側のコマンド:ros2内部でどのようにコマンドが送られているのかわかる -->
`ros2 topic echo`

`ros2 topic pub -r 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0}, angular: {z: 2.0}}"`
- linear x: 直進速度
- angular z: 回転速度


- $package名$/$package名$/my_node.py
```python
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalPublisher(Node):
  def __init__(self):
    super().__init__('minimal_publisher')
    # String型msgをChatter topicへ送信、buffer sizeは10
    self.publisher_ = self.create_publisher(String, 'chatter', 10)
    timer_period = 1.0 # 1秒ごと
    self.timer = self.create_timer(timer_period, self.timer_callback)
    self.count = 0

  def timer_callback(self):
    msg = String()
    msg.data = f'Hello {self.count}'
    self.publisher_.publish(msg)
    self.get_logger().info(f'Publishing: "{msg.data}"')
    self.count += 1

def main(args=None):
  rclpy.init(args=args)
  node = MinimalPublisher()
  rclpy.spin(node)
  node.destroy_node()
  rclpy.shutdown()
````

- `cd ~/colcon_ws`
- `source ~/colcon_ws/install/setup.bash `
- `ros2 run my_py_pkg my_node`