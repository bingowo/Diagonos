#include<stdio.h>
#include <string.h>

#define base 2;
int method(int *a)
{
    int tmp[1003];int i = 0;
    for (;a[i] != 11; ++i)tmp[i] = a[i];tmp[i] = 11;//拷贝到临时数组去
    int x = 0;int k = 0;
    for (;tmp[k] != 11; ++k) {
        x = x*10 + tmp[k];
        a[k] = x/base;
        x =x%base;
    }a[k] = 11;
    return x;
}

int high_plus(int * a,int b){int k = 1;
    if(a[b-1] < 9){a[b-1] += 1;return 0;}
    while(a[b-k] == 9){k++;}a[b-k]++;
    for (int i = b-1; i > b-k; --i)a[i] = 0;
    return 1;
}

int value(const int *a,int k)
{
    int ans = 0;
    for (int i = 0;i < k; ++i){if(a[i] == 0)ans++;}
    return ans == k;
}

int main()
{
    char s[1000];//记录大整数的字符串形式
    int a[1000];//大整数的数字
    int answer[200000];//记录x的值
    gets(s);
    if(s[0] == '0'){printf("0");return 0;}int cnt_c = 0;
    int o;int flag = 1;
    if(s[0] == '-'){o = 1;flag = -1;} else o = 0;
    int i = 0;
    for (; o < strlen(s); ++o,++i) {a[i] = s[o] - '0';}a[i] = 11;

    while(!value(a,i)){
        if(flag == 1){answer[cnt_c++] = method(a);flag = -1;}
        else {int yu = method(a);
            if(yu == 0) {answer[cnt_c++] = yu;flag = 1;}
            else {answer[cnt_c++] = 1;high_plus(a,i);flag = 1;}//高精度加法
        }
    }
    for (int j = cnt_c - 1;j >= 0; --j) {
        printf("%d",answer[j]);
    }
}

