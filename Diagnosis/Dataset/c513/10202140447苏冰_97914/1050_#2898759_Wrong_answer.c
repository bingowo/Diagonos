#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char x[100];
int search1(char s[],char t[])
{
    int len1=strlen(s);
    int len2=strlen(t);
    int k=0;int j=0;
    for(int i=0;i<=len1-len2;i++)
    {
        for(j=i,k=0;j<i+len2;j++,k++)
        {
            x[k]=s[j];
        }
        x[k]='\0';
        if(strcmp(x,t)==0) return i;
    }
    return -1;
}
int search2(char s[],char t[])
{
    int len1=strlen(s);
    int len2=strlen(t);
    int k=0;int j=0;int m=-1;
    for(int i=0;i<=len1-len2;i++)
    {
        for(j=i,k=0;j<i+len2;j++,k++)
        {
            x[k]=s[j];
        }
        x[k]='\0';
        if(strcmp(x,t)==0) m = i;
    }
    return m;
}
int main()
{
    int T;
    scanf("%d",&T);
    char s1[85],s2[85],s[85];
    gets(s1);
    for(int cas=0;cas<T;cas++)
    {
        gets(s1);
        gets(s2);
        gets(s);
        int i1=search1(s,s1);
        int j1=search2(s,s2);
        int ans1=j1-i1+strlen(s2)-2;
        int i2=search2(s,s1);
        int j2=search1(s,s2);
        int ans2=i2-j2+strlen(s1)-2;
        int ans;
        if(i1==-1 || i2==-1) ans=0;
        else if(ans1>ans2) ans=ans1;
        else ans=ans2;
        printf("case #%d:\n%d\n",cas,ans);
    }
    return 0;
}

