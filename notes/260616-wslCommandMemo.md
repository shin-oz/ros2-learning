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