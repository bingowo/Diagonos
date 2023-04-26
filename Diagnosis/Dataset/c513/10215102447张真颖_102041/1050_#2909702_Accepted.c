#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lastfind(char s[],char s1[])
{
    int len=strlen(s),len1=strlen(s1);
    for(int i=len-1;i>=0;i--)
    {
        for(int j=len1-1,t=i;j>=0&&s1[j]==s[t]&&t>=0;j--,t--)
        {
            if(j==0) return t;
        }

    }
    return -1;
}

int firstfind(char s[],char s1[])
{
    for(int i=0;s[i];i++)
    {
        for(int j=0,t=i;s1[j]&&s1[j]==s[t]&&s[t];j++,t++)
        {
            if(j==strlen(s1)-1) return t-strlen(s1)+1;
        }
    }
    return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s1[81]="",s2[81]="",s[82]="";
        int maxnum=0,m=0,last=0,first=0;
        scanf("%s%s%s",s1,s2,s);
        first=firstfind(s,s1);
        last=lastfind(s,s2);
        if(last==-1||first==-1) maxnum=0;
        else if(first==last) maxnum=0;
        else
        {
            maxnum=first<last?last-first-strlen(s2):first-last-strlen(s1);
            first=firstfind(s,s2);
            last=lastfind(s,s1);
            m=first<last?last-first-strlen(s2):first-last-strlen(s1);
            maxnum=m>maxnum?m:maxnum;
        }
        printf("case #%d:\n%d\n",i,maxnum);
    }
    return 0;
}
