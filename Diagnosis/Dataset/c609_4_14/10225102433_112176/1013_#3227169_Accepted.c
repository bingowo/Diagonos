#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 1000000

char s[N];
int f[N];
int ans = 1;

int tran(char c)
{
    if(isdigit(c)) return c-'0';
    else return c-'A'+10;
}

void cput(int num)
{
    for(int i = 0;i < 4;i++)
    {
        f[ans+3-i] = num&1;
        num = num>>1;
    }
    ans += 4;
}

int main()
{
    char c;
    for(int i = 0;i < 2;i++) c = getchar();
    scanf("%s",s);
    for(int i = 0;i < strlen(s);i++) cput(tran(s[i]));
    int begin = 0;
    for(int i = 1;i < ans;i++){
        if(f[i] != 0){
            begin = i;
            break;
        }
    }
    long long a = 0,b = 0;
    for(int i = begin;i < ans;i++){
        int res = f[i];
        long long ra = a,rb = b;
        a = -(ra+rb) + res;
        b = ra-rb;
    }
    if(a != 0 && b != 0){
        if(b == -1){
            printf("%lld-i",a);
        }
        else if(b < -1){
            printf("%lld%lldi",a,b);
        }
        else if (b == 1){
            printf("%lld+i",a);
        }
        else{
            printf("%lld+%lldi",a,b);
        }
    }
    else if(a == 0 && b != 0){
        if(b == -1){
            printf("-i");
        }
        else if(b == 1){
            printf("i");
        }
        else{
            printf("%lldi",b);
        }
    }
    else{
        printf("%lld",a);
    }
    return 0;
}