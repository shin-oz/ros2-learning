#ifndef _CALC_H_ // _CALC_H_が定義されていなければ
#define _CALC_H_ // CALC_H_を定義する

// ヘッダファイルの中でプロトタイプ宣言をする
double avg (double, double);

#endif // 同一コンパイルないで再度includeされた場合、定義済みなのでスキップする(_CALC_H_が定義されていれば2回目以降は何もしない)