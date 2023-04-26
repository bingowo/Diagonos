#include<stdio.h>
#include<string.h>
#include<math.h>

int find(char*s1,char*s2,char*s)
{
    int l1=strlen(s1),l2=strlen(s2),l=strlen(s);
    int d,f,f1=0,f2=0;
    for(int i=0;i<l;i++)
    {
        f=0;
        for(int p=0;p<l1 && p+i<l;p++)
        {
            if(s1[p]!=s[p+i]) break;
            if(p==l1-1) {f=1;f1=i+p+1;}
        }
        if(f) break;
    }
    for(int i=f1+1;i<l;i++)
    {
        f=0;
        for(int p=0;p<l2 && p+i<l;p++)
        {
            if(s2[p]!=s[p+i]) break;
            if(p==l2-1) {f=1;f2=i;}
        }
    }
    if(f1!=0 && f2!=0) d=abs(f1-f2);
    else d=0;
    return d;
}

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s1[81],s2[81],s[81];
        scanf("%s%s%s",s1,s2,s);
        int d1=find(s1,s2,s),d2=find(s2,s1,s);
        printf("case #%d:\n%d\n",i,(d1<d2?d2:d1));
    }
}