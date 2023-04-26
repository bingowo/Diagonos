#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void read(char s[],int n[])
{
    while(*s)
    {
        int f1=0,f=1,a=0,i=0;
        if(*s=='+')s++;
        else if(*s=='-') f=-1,s++;
        while(isdigit(*s)){f1=1;a=a*10+*s-'0';s++;}
        if(a==0&&f1!=1)a=1;
        if(*s!='x'){n[0]=a*f;return;}
        else s++;
        if(*s=='^') s++;
        while(isdigit(*s)){i=i*10+*s-'0';s++;}
        if(i==0)i=1;
        n[i]=a*f;
    }
}
void sol(int a[])
{   char f[45][45]={0};
    int y,i=-20;
    for(i;i<=20;i++)
    {
        y=a[3]*i*i*i+a[2]*i*i+a[1]*i+a[0];
        if(y<=20&&y>=-20)
        {
            f[21-y][i+21]='*';
        }
    }
    for(int n=1;n<=41;n++)
    {
        for(int m=1;m<=41;m++)
        {
            if(f[n][m]=='*')
                printf("*");
            else if(n==1&&m==21)
                printf("^");
            else if(n==21&&m==21)
                putchar('+');
            else if(m==21)
                putchar('|');
            else if(n==21&&m==41)
                putchar('>');
            else if(n==21)
                putchar('-');
            else
                putchar('.');
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    char s[20];
    while(~scanf("%s",s))
    {
        int a[5]={0};
        read(s+5,a);
        sol(a);
    }
    return 0;
}
