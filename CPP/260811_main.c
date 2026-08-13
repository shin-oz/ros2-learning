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

  // int num;
  // printf("1~3の数値を入力してください:");
  // scanf("%d", &num);

  // switch (num) {
  //   case 1:
  //     printf("one\n");
  //     break;
  //   case 2:
  //     printf("two\n");
  //     break;
  //   case 3:
  //     printf("three\n");
  //     break;
  //   default:
  //     printf("不適切な値です。\n");
  // }
  //#####条件分岐のメモここまで 

  // 繰り返しのメモ
  // int i, j;
  // for (i = 1; i <= 2; i++) {
  //   for (j = 1; j <= 3; j++) {
  //     printf("%d+%d=%d ", i, j, i + j);
  //   }
  //   printf("\n");
  // }

  // int i = 0;
  // while ( i <= 5) {
  //   printf("%d ", i);
  //   i++;
  //   printf("\n");
  // }

  // int i = 0;
  // do {
  //   printf("%d ", i);
  //   i++;
  // } while ( i <= 5);
  // printf("\n");
  //##### 繰り返しのメモここまで 

  // 配列のメモ
  // double d[4];
  // double sum, avg;
  // int i;

  // d[0] = 1.2;
  // d[1] = 3.7;
  // d[2] = 4.1;
  // d[3] = 2.0;
  // sum = 0.0;

  // for (i = 0; i < 4; i++) {
  //   printf("%f ", d[i]);
  //   sum += d[i];
  // }
  // printf("\n");
  // avg = sum / 4.0;
  // printf("合計値：%f\n", sum);
  // printf("平均値：%f\n", avg);

  // int n[] = {5,4,3,2,1};
  // int i;
  // for (i = 0; i < 5; i++) {
  //   printf("n[%d]=%d ", i, n[i]);
  // }
  // printf("\n");

  // 文字列型はないので、文字型の配列を使う
  // char s1[4] = {'a', 'b', 'c', '\0'}; //最後に\0のnull文字を入れる
  // char s2[] = "HelloWorld"; //文字列を指定する場合は\0は不要
  // char s3[10];

  // printf("文字列を入力してください");
  // scanf("%s", s3);
  // printf("s1 = %s\n", s1);
  // printf("s2 = %s\n", s2);
  // printf("s3 = %s\n", s3);

  int a[3][4];
  int m,n;
  
  for (m = 0; m < 3; m++) {
    for (n = 0; n < 4; n++) {
      a[m][n] = m + n;
    }
  }

  for (m = 0; m < 3; m++) {
    for (n = 0; n < 4; n++) {
      printf("%d ", a[m][n]);
    }
    printf("\n");
  }
}