// CPP/phase3/01_const_ref_auto_rangefor.cpp を、ノートを見ずに書いて、g++ -std=c++17 -Wall -Wextra で警告なしにビルドしてください。

// double average(const std::vector<double>& v) で平均を返す
// void scale(std::vector<double>& v, double k) で全要素をk倍する（範囲forの auto& を使う）
// int countLonger(const std::vector<std::string>& names, std::size_t n) で、n文字より長い名前の数を返す
// std::map<std::string, int>（センサ名とエラー回数）を const auto& [name, count] で全件出力する
// for (auto x : v) と for (auto& x : v) の両方で要素を書き換えようとし、結果の違いを出力して確かめる

// 書き終えたら、次の2つを口頭で20秒以内に説明できるか試してください。どちらもライブコーディング中に聞かれやすい質問です。

// 「なぜここは const& にしたのか」
// 「auto と const auto& の違いは何か」

// コードをpushしてもらえれば、レビュー観点で確認します。