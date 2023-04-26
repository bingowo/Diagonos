#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define N 100

 void method(int h,char s[],int b)
{
    int sum = 0;
    //将进制为h记录在字符串s[]中的数据转换为十进制，用sum记录
    for(int i = 0;i < strlen(s);i++)
    {
        if('0' <= s[i] <= '9')
        {
            sum = sum*h + (s[i] - '0');
        }
        else if('A' <= s[i] <= 'Z')
        {
            sum = sum*h + 10 + (s[i] - 'A');
        }
        else if('a' <= s[i] <= 'z')
        {
            sum = sum*h + 10 + (s[i] - 'a');
        }
    }
    printf("%d\n",sum);
    char x[N];//
    char d[37] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int c = 0;
    int e = sum;
    int f = b;
    do
    {
        x[c] = d[e % f];
        c++;
        e = e/f;

    }while(e > 0);

    x[c] = 0;

    for(int i = 0,j = c - 1;i < j; i++,j--)
    {
        char e;
        e = x[i];
        x[i] = x[j];
        x[j] = e;
    }

    printf("%s\n",x);


}

int main()
{
    int n;
    char s[N];
    int a;
    scanf("%d %s",&n,s);
    scanf("%d",&a);
    method(n,s,a);

    return 0;
}