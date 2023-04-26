#include <stdio.h>
#include <string.h>
void solve(char *s);
int gcd(int a, int b){
    return a ? gcd(b % a, a) : b ;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T--){
        char s[121];
        gets(s);
        solve(s);
        return 0; 
    }
}

void solve(char *s)
{
    int s1  = 0, bytes=strlen(s), i, j;
    for (int i = 0; i < bytes; i++){
        unsigned char c= s[i]; //为了使用逻辑右移，定义为无符号字符类型
        for (j = 0; j < 8; j++){
            s1 += c % 2; //统计1的位数
            c>>=1; //逻辑右移
        }
    }
    int g = gcd(s1, bytes * 8);//最大公约数
    printf ("%d/%d", s1/g, bytes * 8 / g);

}