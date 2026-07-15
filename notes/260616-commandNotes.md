## linux command
- OSやカーネル情報を表示する
`uname -a`

- OS情報ファイルを表示する 
`cat /etc/os-release`

- linuxのpackage listを最新化する
`sudo apt update`

- package listをもとに実際に新しいバージョンにする
`sudo apt upgrade`

- package listにない新しいソフトのinstall
`sudo apt install <package名>`

- cpuアーキテクチャを確認
`dpkg --print-architecture`

- 必要な親ディレクトリも一緒に作成
`mkdir -p`

- ディレクトリを削除
`rm -rf`
r: ディレクトリだけでなくその中身も削除する
f: 確認なしで削除する

- 移動or名前の変更
`mv`

- 権限変更コマンド change mode
chmod

- 標準入力の内容をファイルに保存する
`tee`

- ヒアドキュメント：EOFまでの複数行をまとめて入力する　
<<EOF

## git command
- staging areaから戻す
`git restore --staged .`
