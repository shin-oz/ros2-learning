↓のURLを参考にinstallした
https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository

ca-certificates ->HTTPS通信の証明書確認ツール
curl ->URLからファイル取得するツール

systemd = Linuxのサービス管理システム
これがdockerなどのdeamonを起動する

gpgキー
入手するパッケージが公式配布のものか確認するもの

- docker-ce
community edition -> docker engine本体
- docker-ce-cli
dockerコマンド
- containerd.io
docker内部でコンテナを動かす低レイヤruntime?
- docker-buildx-plugin
高機能のdocker build
- docker-compose-plugin
compose: コンテナをまとめて管理する仕組み
