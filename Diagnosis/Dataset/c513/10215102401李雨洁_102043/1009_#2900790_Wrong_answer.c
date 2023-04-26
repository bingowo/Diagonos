#include <stdio.h>
#include <string.h>

int gcd(int m,int n)//求最大公约数
{
    return n ? gcd(n,m%n) : m;
}

int COUNT(char value1)//求1的个数
{
    int value=(int)value1;
    int i,count = 0;
    for(i=0;i<32;i++)
    {
        if (value&1) count++;
        value = value>>1;
    }
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        char str[121] = {'\0'};
        char ch;
        int index = 0;
        while((ch = getchar()) != '\n')
            str[index++] = ch;
        int len = strlen(str);
        int A = 0;  //A代表分子
        for(int j = 0; j < len; j++)
            A += COUNT(str[j]);
        int B = len * 8; //B代表分母
        int g = gcd(A, B);
        A /= g;
        B /= g;
        printf("%d/%d\n", A, B);
    }
    return 0;
}
