#include <stdio.h>
#include <math.h>
#include <string.h>

char s[1000] = {0};
char ch[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void reverse(char *x)
{
    unsigned len = strlen(s);
    for(int i = 0;i < len/2;i++)
    {
        char c = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = c;
    }
}

int tran(int num,int n)
{
    if(num%n < 0)
    {
        int res = num-(num/n+1)*n;
        return res;
    }
    else
    {
        return num%n;
    }
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int cnt = 0;
    while(a)
    {
        s[cnt++] = ch[tran(a,b)];
        if(a%b < 0)
            a = a/b+1;
        else
            a /= b;
    }
    reverse(s);
    printf("%s",s);
    return 0;
}