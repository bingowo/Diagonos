#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int readstring(char*s)
{
    int refer[128]={0};
    int l=strlen(s),ans=0;
    for(int i=0;i<l;i++)
    {
        if(refer[(int)s[i]]==0)
        {refer[(int)s[i]]=1;ans++;}
    }
    return ans;
}

int cmp(const void*a,const void*b)
{
    char*a0=(char*)a,*b0=(char*)b;
    int cnt1=readstring(a0),cnt2=readstring(b0);
    if(cnt1>cnt2) return -1;
    else if (cnt1<cnt2) return 1;
    else return strcmp(a0,b0);
}

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;scanf("%d",&n);
        char s[n][21];
        for(int t=0;t<n;t++) scanf("%s",s[t]);
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int t=0;t<n;t++) printf("%s\n",s[t]);
    }

    return 0;
}