- OSやカーネル情報を表示する
uname -a

- OS情報ファイルを表示する 
cat /etc/os-release

- linuxのパッケージの更新
sudo apt-get update

- ↑との違いは？
sudo apt update
sudo apt upgrade

- install
sudo apt install


https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository
ca-certificates ->HTTPS通信の証明書確認ツール
curl ->URLからファイル取得するツール

- systemd = Linuxのサービス管理システム
これがdockerなどのdeamonを起動する

- chmod
change mode ->権限変更コマンド

- gpgキー
入手するパッケージが公式配布のものか確認するもの

- tee
標準入力の内容をファイルに保存する

- <<EOF
ヒアドキュメント：EOFまでの複数行をまとめて入力

- APT: Advanced Package Tool
ソフトをインストール・更新・削除する仕組み
linuxはaptを使ってインストールする
→リポジトリを使って依存関係とかも自動で解決してくれる？必要なパッケージも一緒にインストールしてくれる？　

- docker-ce
community edition -> docker engine本体

- docker-ce-cli
dockerコマンド

- containerd.io
docker内部でコンテナを動かす低レイヤruntime?

- docker-buildx-plugin
高機能のdocker build?

- docker-compose-plugin
compose: コンテナをまとめて管理する仕組み

- nvidia-smi
nvidia系コマンド

- dpkg --print-architecture
cpuアーキテクチャを確認

amd64 = x86_64
amdが最初に64bit拡張版を作成したためintelでもamd64と表示される

uname -aはx86_64と応答がある

arm64とは？
arm系アーキテクチャ
macやスマホなどこっち
消費電力が小さかったりする

- jenkinsとは？
CI/CDツール
最近はgithub automateもあるが
ビルド・テスト・デプロイを自動化するツール

- instanceとは？
実際に起動している実体

- localeとは？
表示言語や文字コードや日付の表示形式など、linuxの言語・地域設定のこと
Cとは？最小設定の、英語前提のlocaleのこと

- posix
Portable Operating System Interface
unix系OSの共通ルール

- ros2 middleware
talker nodeとlistener nodeは直接通信していない
RMW(ros middleware)を使ってDDS(data distribution service)通信をする
大量のlidarデータなどを使うときはRMWをjazzy標準のFast DDSでなくCyclone DDSとかにしたほうが通信が早いことがあるらしい

https://docs.ros.org/en/jazzy/Tutorials.html

- middleware
OSとapplicationの間に入って、共通機能を提供するソフトウェア

- mkdir -p
親ディレクトリも一緒に作成

- rm -rf
r: ディレクトリだけでなくその中身も削除する
f: 確認なしで削除する

-mv
移動コマンドだが、名前を変更することもできる