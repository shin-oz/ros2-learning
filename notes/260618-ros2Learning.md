# memo

ros2とは
→OSとアプリ(Autowareなど)の間のミドルウェア

## 用語リスト
- package
アプリケーションの構成単位
複数のnodeによりpackage(アプリケーション)が構成される

- ROS master
各nodeを管理し、node間を接続するサーバ
rescoreコマンドによってROS masterを起動する
**ROS2で削除された概念**

- Message
node間でやりとりされる情報
一方向のTopicと双方向のServiceがある

- node
単純なlinuxプログラムの個々
センサから数値を読み取る、モータの回転数を制御する　など
Lidarを用いた自己位置推定では、センサドライバ→センサデータ処理→自己位置推定　の３つのノードが動作する

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
- build system: ament ->何をどうbuildするかのルールを定義
- build tool: colcon ->buildを実際に実行するツール

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
# 1. packageのひな形を作成する
ros2 pkg create --build-type ament_python my_package

# 2. コードを編集（src/my_package/my_package）

# 2. build
cd ~/ros2_ws
colcon build --packages-select my_package

# 3. 環境を反映
source install/setup.bash

# 4. 実行
ros2 run my_package my_node
```

### 実際の手順
1. ワークスペース作成
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws
tree -L 2 # ディレクトリ構成を深さ2階層まで表示する

2. amentを使ってpackageのtemplateを作成する
cd ~/ros2_ws/src
'# package名はmy_package、ament_pythonのビルドシステムを使う
ros2 pkg create --build-type ament_python my_package

```
src/my_package
├── package.xml # packageの依存関係
├── setup.py # build時に利用する設定ファイル
├── setup.cfg # python packageをどうインストールするか定義
├── resource
│   └── my_package # buildするとこのファイルがinstall/に登録される。
└── my_package # この中にpackageを作成する
    └── __init__.py # 他ファイルからimportできるようにpythonモジュールであることを宣言
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
