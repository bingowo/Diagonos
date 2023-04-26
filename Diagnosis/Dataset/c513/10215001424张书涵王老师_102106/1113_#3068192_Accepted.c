#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct element
{
    char s[101];
};

void reverse(char*s)
{
    int i,j;
    char c;
    for(i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

void add(char*s1,char*s2)
{
    if(s1[0]==0)
    {
        int lenth2=strlen(s2);
        int i;
        for(i=0;i<lenth2;i++)
            s1[i]=s2[i];
    }
    else
    {
        int lenth1=strlen(s1),lenth2=strlen(s2);
        int c[1000]={0};
        int i;
        reverse(s1);reverse(s2);
        if(lenth1>lenth2)
        {
            for(i=lenth2;i<lenth1;i++)
                s2[i]='0';
        }
        if(lenth1<lenth2)
        {
            for(i=lenth1;i<lenth2;i++)
                s1[i]='0';
        }
        int lenth=lenth1;
        lenth1=strlen(s1);
        for(i=0;i<lenth1;i++)
            c[i]=s1[i]-'0'+s2[i]-'0';
        for(i=0;i<(lenth1+1);i++)
        {
            if(c[i]>=10)
            {
                if(i==lenth1-1)
                    lenth++;
                c[i+1]=c[i+1]+c[i]/10;
                c[i]=c[i]%10;
            }
        }
        for(i=0;i<lenth1;i++)
            s1[i]=0;
        for(i=0;i<lenth;i++)
            s1[i]=c[i]+'0';
        for(i=lenth2;i<lenth1;i++)
            s2[i]=0;
        reverse(s2);
        reverse(s1);
    }
}

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    struct element dp[101]={0};////dp[n]表示第n项的值
    //特殊情况，也就是前面不足k项的时候
    dp[0].s[0]='0';dp[1].s[0]='1';
    int lenth,i;
    for(lenth=2;lenth<k;lenth++)
    {
        for(i=lenth-1;i>=0;i--)
            add(dp[lenth].s,dp[i].s);
    }
    if(n>=k)
    {
        for(lenth=k;lenth<n;lenth++)
        {
            for(i=lenth-1;i>=(lenth-k);i--)
                add(dp[lenth].s,dp[i].s);
        }
    }
    printf("%s",dp[n-1].s);
}