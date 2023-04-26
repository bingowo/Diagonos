#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b)
{
    return (a>b?a:b);
}
int main()
{
    char s[51];
    int cnt[51];
    int m;
    char a;
    int maxn=1;
    while((a=getchar())==' ' || a=='\n'); 
    gets(s);
    m=strlen(s);
    cnt[0]=1;
    for(int i=1;i<m;i++)
    {
        if(s[i]!=s[i-1])
        {
            cnt[i] = cnt[i-1]+1;
            maxn = max(cnt[i],maxn);
        }
        else 
            cnt[i] = 1;
    }
    printf("%d\n",maxn);
    return 0;
}