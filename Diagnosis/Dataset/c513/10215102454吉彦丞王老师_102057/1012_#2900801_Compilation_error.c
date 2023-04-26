#include<stdio.h>
#include<strng.h>
long long int zhishu(char a,int b)
{
    long long int x=a='0';
    for(int i=0;i<b;i++)
    {
        x=x*10;
    }
    return x;
}
long long int change(char s[],int n,int m)
{
    long long int y=0;
    for(int i=n;i<m;i++)
    {
        y=y+zhishu(s[i],m-n);
    }
    return y;
}
int main()
{
    char s[10];
    scanf("%s",&s);
    int l=strlen(s);
    if(s[0]=='-')
    {
        int n=0;
        for(int i=1;i<l&&s[i]!='+';i++)
        {
            n++;
        }
        int a=0;
        for(int j=i-n;j<i;j++)
        {
            a=a+change(s,j,i)
        }
    }
}