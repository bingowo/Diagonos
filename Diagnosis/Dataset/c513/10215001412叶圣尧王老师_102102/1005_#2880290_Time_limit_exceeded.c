#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void solve(char*p,int len)
{
    int i=0,d;char arr[100];double k=0.125,f=0;
    while(i<len-2)
        f=p[len-1-i]-'0'+f*k;
    gcvt(f,20,arr);
    printf("%s",arr);
    
}

int main()
{
    int T,i,j=0,len;char s[52];
    scanf("%d",&T);
    while(scanf("%s",s)!=EOF)
    {
        printf("case #%d:\n",j++);
        len=strlen(s);
        solve(s+2,len);
    }
}