## moemo

## OS
### OS: opearting systemとは
→ユーザーとアプリケーションとアプリケーションの間に立ち、効率多岐な管理を行うソフトウェア
※アプリケーションは一つの者に特化したもの

アプリケーションがハードウェアをつかうとき、リソース管理を行ったりする

### OSの機能
ユーザー管理
ファイル管理：SSDなどの記録媒体にファイル書き込みや読み込みを管理する
入出力管理：マウスやキーボードなどの周辺機器の制御や管理を行う
タスク管理：CPUやメモリなどのリソースを効率的に割り当てる
メモリ管理：アプリケーションが動作する際のメモリ領域を管理する

### カーネルとシェル
OSはkernelとshellに分けられる
kernel：OSの核でハードウェアやアプリケーションを管理している。ユーザが自由に操作うることはできない
shell：kernelを直接触れないようにkernelとユーザをつなぐのか通訳する

### linuxとは
#### どんなosか
unixとどう機能のosを目指して作ったため、unix系osの一つ
本来linuxはosのkarnelを指す
オープンソースでソースコードが公開されているため、独自部品に対応できるようにサーバや家電などのOSとしても広く使われる

1969  AT&Tのベル研究所でUnics(のちにUnix)が開発、設計内容が公開されていた
1981  IBM PC(personal computer)発売
1991  非力なPCでも使えるUnixに似たosであるLinuxを公開

#### メリデメ
メリット  ほとんど無料で使え、specの低いコンピュータでも動く
デメリット  windowsやmacのアプリが使えないことがある

#### distoributionの意味と種類
本来、linuxはkarnelのことを指していた
windowsやmacはkarnel以外のshellやアプリケーションなども含んでいる
karnel以外のアプリケーションを組み合わせたものがdistribution

- Red Hat Enterprise Linux(RHEL)
商用向けで有名、有料→止まったら困るものにはRed Hat
- Ubuntu
Debianからの派生
windowsやmacに操作感が近いため、普段しやすい
- CentOS
Red Hatの完全互換を目指していた
無償で利用できるがサポートなし
EOL済み

### 起動とログイン、シャットダウン
#### 起動の手順
1. 電源入る
2. UEIF起動（ハードウェアチェックとブートローダ実行）
3. OS起動

#### CUI環境におけるシャットダウン
複数ユーザで使ったりしていたり、業務サービスが動いていたりするため、root権限で実行する必要あり
`sudo shutdown -h now`
`sudo shutdown -r 20:40 "reboot at 20:40"`
`sudo shutodown -c` <!-- shutdownをキャンセルする -->

### SSHとは
ネットワークに接続された機器との通信を暗号化して操作する
→例えば、なりすましユーザによるサーバ接続を防ぐとか
OpenSSHというソフトを使う

#### 認証方法
公開鍵認証か共通鍵認証
→共通鍵だと漏れるかもしれないので、公開鍵を基本的に使う

1. 秘密鍵と公開鍵をclient側で作成する
2. 公開鍵を接続先へ送る
3. clientのみがもつ秘密鍵とのペアの公開鍵をもつならば、接続先が正しい→接続先を認証完了
4. clientへ公開鍵を使って暗号を作成し、秘密鍵で正しく暗号が解析されれば正しい→接続元を認証完了

#### SSHの使い方
##### client側の関係ファイル
- ssh_config  client側のssh設定ファイル
- id_rsa      秘密鍵
- id_rsa.pub  公開鍵
- known_hosts  接続先サーバの情報や送られてきたホスト認証のために送信済みの公開鍵

sshディレクトリは
`/home/$USER/.ssh/ssh_config`
`/etc/ssh/ssh_config` ←ユーザ間で共通の場合

##### host側の関係ファイル
- sshd_config
- ssh_host_rsa_key
- ssh_host_rsa_key.pub
- authorized_keys

sshディレクトリは
`/etc/ssh/ssh_config`
`/home/$USER/.ssh/authrozed_keys` ←ユーザーによって登録される公開鍵が異なるのでこれだけ場所が異なる

#### sshの設定方法
秘密鍵と公開鍵のペア作成方法
→/home/$USER/.sshに作成される
`ssh-keygen`

公開鍵をリモートホストへ登録　※パスワード方式や認証などをホストとそろえる必要あり
host側の~/.ssh/authorized_keysに保存される
`ssh-copy-id $接続先アカウント名@$接続先ホスト名`

sshでログイン ※接続先ホスト名はipアドレス出も可能
`ssh $接続先アカウント名@$接続先ホスト名`

ログアウト
`logout` or `exit` or `ctrl + d`