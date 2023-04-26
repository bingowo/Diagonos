#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void zhuan(char*p,int lenth,int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        p[i]=lenth%2+'0';
        lenth/=2;
    }
}

int main()
{
    void zhuan(char*p,int lenth,int n);
    char s[500];char num[10];int i=0,j,k=0,lenth;
    scanf("%s",s);
    printf("0001");
    lenth=strlen(s);
    zhuan(char *num,lenth,10);
    printf("%s",num);
    for(i=0;i<lenth/3;i++)
    {
        for(j=i*3;j<i*3+3;j++)k=k*10+s[j]-'0';
        zhuan(char *num,k,10);
        printf("%s",num);
        k=0;
    }
    for(j=i*3;j<lenth-1;j++)k=k*10+s[j]-'0';
    char e[(lenth%3)*3+1];
    zhuan(e,k,(lenth%3)*3+1);
    printf("%s",num);
}