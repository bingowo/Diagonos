#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

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

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s1[81]="",s2[81]="",s[82]="",*first;
        int maxnum=0,last=0;
        scanf("%s%s%s",s1,s2,s);
        first=strstr(s,s1);
        last=lastfind(s,s2);
        if(last==-1||first==NULL) maxnum=0;
        else
        {
            maxnum=abs(first+strlen(s1)-s-last);
            first=strstr(s,s2);
            last=lastfind(s,s1);
            if(abs(last-(first+strlen(s2)-s))>maxnum)
                maxnum=abs(first+strlen(s2)-s-last);
        }
        printf("case #%d:\n%d\n",i,maxnum);
    }
    return 0;
}