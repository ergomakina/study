#include <stdio.h>
#include <string>   //strtok関数用
#include <stdlib.h> //strtoul関数用

int main(void)
{
    char ch1;      // 変換後の取得値
    char *p1, *p2; // char型ポインタワーク

    //== 変換元の文字列 ==
    char sHex[] = {"30 31 32 41 42 43 4A 4B 4C 50 51 52 Hoge"};
    char *delim = ", "; //デリミタ（複数渡せる）ここではカンマと空白
    char *ctx;

    //== 変換処理（スペース区切りで分割した文字列の数値変換）==
    p1 = strtok_s(sHex, delim, &ctx); // 1個目の部分文字列取得
    while (p1 != NULL)
    {
        ch1 = (0xffU & strtoul(p1, &p2, 16)); // 16進文字列と解釈してchar型数値に変換
        if (p1 != p2)
        {
            printf("\"%s\" ==> '%c'\n", p1, ch1); // 変換成功時の表示
        }
        else
        {
            printf("\"%s\" ==> ** NG **\n", p1); // 変換失敗時の表示
        }
        p1 = strtok_s(NULL, delim, &ctx); // 2個目以降の部分文字列取得
    }

    return 0;
}