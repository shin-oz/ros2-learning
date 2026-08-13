// ヘッダファイルの読み込み
// .hはC言語のヘッダファイル拡張子
# include <stdio.h>

void main() {
  // #####ここから演算と変数の実行メモ
  // // %s: 後に続く文字列を出力する
  // // %d: 後に続く整数を出力する
  // // %c: 後に続く文字を出力する
  // printf("こんちは。私の名前は%sです。\n年齢は%dです。\n", "山田太郎", 20);
  // printf("イニシャルは、%cです。\n", 'Y');
  // printf("%f + %f = %f\n", 1.2, 2.7, 1.2 + 2.7);
  
  // printf("%d + %d = %d\n", 5, 2, 5 + 2);
  // printf("%d - %d = %d\n", 5, 2, 5 - 2);
  // printf("%d * %d = %d\n", 5, 2, 5 * 2);
  // printf("%d / %d = %d 余り%d\n", 5, 2, 5 / 2, 5 % 2);

  // int i1, i2, j1, j2;
  // double d1, d2, e1, e2;

  // j1 = 3;
  // j2 = 3;

  // d1 = 1.23;
  // d2 = 1.23;

  // i1 = d1;
  // i2 = (int)d2;

  // e1 = j1;
  // e2 = (double)j2;

  // printf("d1 = %f d2 = %f\n", d1, d2);
  // printf("i1 = %f i2 = %f\n", i1, i2);
  // printf("j1 = %f j2 = %f\n", j1, j2);
  // printf("e1 = %f e2 = %f\n", e1, e2);
  //#####演算と変数のメモここまで 
  
  // #####ここから条件分岐メモ
  // int num;
  // printf("1~3の値を入力してください: ");
  // scanf("%d", &num);

  // if (num == 1) {
  //   printf("one \n");
  // } else if (num == 2) {
  //   printf("two\n");
  // } else if (num == 3) {
  //   printf("three \n");
  // } else {
  //   printf("不適切な値です\n");
  // }

  // int dice;
  // printf("1から6の数値を入力してください:");
  // scanf("%d", &dice);
  // if (1 <= dice && dice<= 6) {
  //   if (dice == 2 || dice == 4 || dice == 6) {
  //     printf("チョウです。\n");
  //   }
  //   else {
  //     printf("ハンです。\n");
  //   }
  // }
  // else {
  //   printf("範囲外の数値です。\n");
  // }

  int num;
  printf("1~3の数値を入力してください:");
  scanf("%d", &num);

  switch (num) {
    case 1:
      printf("one\n");
      break;
    case 2:
      printf("two\n");
      break;
    case 3:
      printf("three\n");
      break;
    default:
      printf("不適切な値です。\n");
  }

}