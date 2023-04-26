#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary(int num)
{
    int a[10]={0};
    int i=-1;
    while(num!=0&&i<=8)
    {
        a[++i]=num%2;
        num/=2;
    }
    for(i=9;i>=0;i--)
    printf("%d",a[i]);
}
int main()
{
    char s[1000];
    scanf("%s",s);
    printf("0001");
    int len=strlen(s);
    binary(len);
    if(len%3==0)
    {
        for(int i=0;i<len-3;i+=3)
        {
            char a[1000];
            a[i]=s[i];
            a[i+1]=s[i+1];
            a[i+2]=s[i+2];
            binary(atoi(a));
        }
    }
    if(len%3==1)
    {
        for(int i=0;i<len-4;i+=3)
        {
            char a[1000];
            a[i]=s[i];
            a[i+1]=s[i+1];
            a[i+2]=s[i+2];
            binary(atoi(a));
        }
        int a[4]={0};
        int i=-1,num=s[len-1]-'0';
        while(num!=0&&i<=4)
        {
            a[++i]=num%2;
            num/=2;
        }
        for(i=3;i>=0;i--)
        printf("%d",a[i]);
    }
    if(len%3==2)
    {
         for(int i=0;i<len-5;i+=3)
        {
            char a[1000];
            a[i]=s[i];
            a[i+1]=s[i+1];
            a[i+2]=s[i+2];
            binary(atoi(a));
        }
        int a[7]={0};
        int i=-1,num=s[len-1]-'0'+(s[len-2]-'0')*10;
        while(num!=0&&i<=7)
        {
            a[++i]=num%2;
            num/=2;
        }
        for(i=6;i>=0;i--)
        printf("%d",a[i]);
    }
    return 0;
}