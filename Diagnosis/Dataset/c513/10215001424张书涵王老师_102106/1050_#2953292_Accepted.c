#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s1location(char *s1,char*s)
{
    int i,j,k;
    int l1,n;
    l1=strlen(s1);
    for(i=0;s[i];i++)
    {
        n=0;
        for(j=i,k=0;(s1[k]==s[j])&&k<l1;j++,k++)
            n=n+1;
        if(n==l1)
        {
            if(l1==1)
                return (j-1);
            else
                return (j-1);
        }
    }
    if(n==0)
        return -1;
}

int s2location(char*s2,char*s)
{
    int i,j,k;
    int l1,l2,n;
    l1=strlen(s2);l2=strlen(s);
    for(i=l2-1;i>=0;i--)
    {
        n=0;
        for(j=i,k=l1-1;(s2[k]==s[j])&&k>=0;j--,k--)
            n=n+1;
        if(n==l1)
        {
            if(l1==1)
                return (j+1);
            else
                return (j+1);
        }
    }
    if(n==0)
        return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s1[90]={0};
        char s2[90]={0};
        char s[90]={0};
        scanf("%s%s%s",s1,s2,s);
        int l1,l2,l;
        l1=s1location(s1,s);
        l2=s2location(s2,s);
        if(l1==-1||l2==-1)
            l=0;
        else
            l=l2-l1-1;
        printf("case #%d:\n",i);
        if(l<0)
        {
            l1=s2location(s1,s);
            l2=s1location(s2,s);
            l=l1-l2-1;
            if(l<=0)
                printf("0\n");
            else
                printf("%d\n",l);
        }
        else
        {
            printf("%d\n",l);
        }
    }
}