#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int cnt=0;
char t[30];
int f(char s[])
{
    cnt++;
    int i=strlen(s)-1,j=0;
    for(i=strlen(s)-1,j=0;i>=0;i--,j++)
    {
        t[j]=s[i];
    }
    t[j]='\0';
    int m=atoi(s);int n=atoi(t);
    int v=m+n;int flag=0;
    char x[30]={0};
    sprintf(x,"%d",v);
    for(int i=0,j=strlen(x)-1;i<j;i++,j--)
    {
        if(x[i]!=x[j])
        {
            flag=0;break;
        }
        else flag=1;
    }
    if(flag==0) v=f(x);
    return v;
}
int main()
{
    char s[30];
    scanf("%s",s);
    int ans=f(s);
    printf("%d %d",cnt,ans);
    return 0;
}
