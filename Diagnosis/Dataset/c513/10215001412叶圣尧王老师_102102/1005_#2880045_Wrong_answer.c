#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void solve(char*p,int len)
{
    int i,d;char arr[100];double k=0.125,f=0;
    for(i=0;i<len;i++)
    {
        d=(p[i]-'0')*k+f;
        f=(p[i]-'0')*k+f-d;
        arr[i]=d+'0';
        k=k*0.125;
    }arr[i]='\0';
    printf("%s\n",arr);
}

int main()
{
    int T,i,j=0,len;char s[52];
    scanf("%d",&T);
    while(scanf("%s",s)!=EOF)
    {
        printf("case #%d:\n0.",j++);
        len=strlen(s)-2;
        solve(s+2,len);
    }
}