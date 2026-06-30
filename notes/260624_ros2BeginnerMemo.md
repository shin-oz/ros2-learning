# 260624_ros2BeginnerMemo.md

## ros2とは？
目的：ロボット開発を効率化する

ros1との違い
- リアルタイム性向上
- 分散システム対応
- セキュリティ強化

## Dockerとは？
アプリケーションとその実行環境をコンテナとしてまとめて動かす技術
- 環境の再現性が高い
OSやライブラリ違いなどの環境依存の不具合を防ぎ、開発者間で環境の共有が可能
- OSすべてを起動しないので仮想マシンより高速
- システムごとに分離できる
コンテナ単位で切り替えや検証が可能

## Dockerの基本概念
- ホストOS
Dockerの土台となる実行環境-> WSLのUbuntuなど
- Docker Image
OSやアプリ、設定がまとまったtemplate
読み取り専用
起動時にコンテナとして展開（コンテナは実行した中身）
- Container
Imageをもとに作成された実行中の環境

## Dockerの基本操作
- imageを確認
`docker images`

- imageをpull
`docker pull debian`
 
- containerの状態を確認
`docker ps -a`

- docker containerを立ち上げ
`docker run -dit --name mytest debian`
-d containerをbackgroundで実行
-it 対話モードでコマンドラインから操作

- 起動中のcontinerに接続
`docker exec -it mytest bash`
eixtで抜けてもcontinerはbackgroundで起動している

- containerを停止
`docker stop mytest`

- containerを削除
`docker rm mytest`

- imageの削除
`docker rmi XXX`

## Dockerを使ったROS2環境の構築
osrf提供の公式imageがある　
docker hubからImageをpullする
`docker pull osrf/ros:jazzy-desktop`

- dockerコンテナを起動
```
docker run -it --rm --net=host \
 --env DISPLAY=$DISPLAY \
 --env WAYLAND_DISPLAY=$WAYLAND_DISPLAY \
 --env XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR \
 --env QT_X11_NO_MITSHM=1 \
 --volume /tmp/.X11-unix:/tmp/.X11-unix \
 osrf/ros:jazzy-desktop
```
--rm
containerを止めると自動で削除する
--net=host
hostとネットワークを共有
--env
GUI表示のための環境変数を設定する
--volume
x11 socketでGUI表示する

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

## pythonパッケージを作成する
1. wsを作成する
ws ->ros2 packageをまとめて管理・buildするための作業スペース
ros2では機能ごとにpackageでまとめる

2. $ws$/src内で`ros2 pkg create my_py_pkg --build-type ament_python --dependencies rclpy std_msgs geometry_msgs`
ros2 pkg create $package名$ --build-type ament_python --dependencies
--dependenciesでこのpackageが使用する他packageの依存関係を示す

**ros2 pkg createするときの--dependenciesを間違えてstd masgsになってるので修正必要**

```
$package名$/package.xml ->packageの基本情報(名前など)と依存関係(rclpyやstd_msgsなど)
$package名$/setup.py ->python package installのための設定を記述。ros2 runのためのentry pointを記述しておく
$package名$/$package名$/ ->この中にpython packageを記述していく　
$package名$/init.py ->python実行に必要で、編集扶養
```
- $package名$/setup.py のentry pointで\$node名\$で起動できるようにする
'$node名$ = $package名$.$file名$:main'

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