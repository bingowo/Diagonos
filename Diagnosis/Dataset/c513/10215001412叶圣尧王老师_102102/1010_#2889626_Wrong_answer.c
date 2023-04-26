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
    char s[500];char num[10],e[10];int i,j,k=0,lenth;
    scanf("%s",s);
    printf("0001");
    lenth=strlen(s);
    zhuan(num,lenth,10);
    printf("%s",num);
    for(i=0;i<lenth/3;i++)
    {
        for(j=i*3;j<i*3+3;j++)k=k*10+s[j]-'0';
        zhuan(e,k,10);
        printf("%s",e);
        k=0;
    }
    for(j=i*3;j<lenth-1;j++)k=k*10+s[j]-'0';
    zhuan(num,k,lenth*3-i*9+1);
    printf("%s",num);
}