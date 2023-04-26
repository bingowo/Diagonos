#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;

void print(int x)
{
    int temp[10];
    memset(temp,0,sizeof(int));
    for(int j=0;j<10;j++)
    {
        temp[10-j-1]=x&1;
        x>>=1;
    }
    for(int j=0;j<10;j++)
    {
        printf("%d",temp[j]);
    }
}

int T(char c)
{
    return((int)(c-'0'));
}
int main()
{
    printf("0001");
    char s[510];
    scanf("%s",s);
    s[strlen(s)]='\0';
    print(strlen(s));
    int m,main=(strlen(s)/3)*3,rest=strlen(s)%3;
    for(int i=2;i<main;i+=3)
    {
        m=T(s[i])+T(s[i-1])*10+T(s[i-2])*100;
        print(m);
    }
}
