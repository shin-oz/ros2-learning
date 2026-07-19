# 260624_dockerMemo.md

## Dockerとは？
アプリケーションとその実行環境をコンテナとしてまとめて動かす技術
メリット
- 環境の再現性が高い(OSやライブラリ違いなどの環境依存の不具合を防ぎ、開発者間で環境の共有が可能)
- OSすべてを起動しないので仮想マシンより高速
- システムごとに分離できる(コンテナ単位で切り替えや検証が可能)

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
<!-- --rm -->
<!-- containerを止めると自動で削除する -->
<!-- --net=host -->
<!-- hostとネットワークを共有 -->
<!-- --env -->
<!-- GUI表示のための環境変数を設定する -->
<!-- --volume -->
<!-- x11 socketでGUI表示する -->
```