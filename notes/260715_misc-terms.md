## ros2 middleware
talker nodeとlistener nodeは直接通信していない
RMW(ros middleware)を使ってDDS(data distribution service)通信をする
大量のlidarデータなどを使うときはRMWをjazzy標準のFast DDSでなくCyclone DDSとかにしたほうが通信が早いことがあるらしい

## middleware
OSとapplicationの間に入って、共通機能を提供するソフトウェア

## APT: Advanced Package Tool
ソフトをインストール・更新・削除する仕組み
linuxはaptを使ってインストールする

## CPUアーキテクチャ
amd64 = x86_64
amdが最初に64bit拡張版を作成したためintelでもamd64と表示される

`uname -a`はx86_64と応答がある

arm64とはarm系アーキテクチャ
macやスマホなどこっち
消費電力が小さかったりする

## jenkinsとは
CI/CDツール
最近はgithub automateもあるが
ビルド・テスト・デプロイを自動化するツール

## instanceとは
実際に起動している実体

## localeとは
表示言語や文字コードや日付の表示形式など、linuxの言語・地域設定のこと
※Cとは最小設定の、英語前提のlocaleのこと

## posix
Portable Operating System Interface
unix系OSの共通ルール