class CSample {
  public:
    void setNum(int num); // private指定のメンバ変数を書き込む
    int getNum(); // private指定のメンバ変数を読み出す　
  private:
    // カプセル化
    int m_num; // メンバ変数は原則的にはプライベートにして外部から直接触ることができないようにする
};