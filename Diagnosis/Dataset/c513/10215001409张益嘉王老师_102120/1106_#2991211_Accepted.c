#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000000007


int zhongshu(char s[],int i)
{
    int len=strlen(s),co=1;
    if(len==1) return 1;
    if(i==0)
    {
        if(s[i]==s[i+1]) return 1;
        else return 2;
    }
    else if(i==len-1)
    {
        if(s[i]==s[i-1]) return 1;
        else return 2;
    }
    else
    {
        if((s[i]!=s[i+1])&&(s[i]!=s[i-1])&&(s[i-1]!=s[i+1])) return 3;
        else if((s[i]!=s[i+1])||(s[i]!=s[i-1])) return 2;
        else return 1;
    }
}


int main()
{
    char s[1010];
    scanf("%s",s);
    long long i,len,mid,re=1;
    //int a[1010];
    //memset(a,0,sizeof(int)*1010);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        mid=zhongshu(s,i);
        re*=(long long)(mid%M);
        re%=(long long)M;
        //printf("[%d]=%d\n",i,mid);
    }
    //for(i=0;i<a.wei;i++) printf("(%d)",a.shu[i]);
    printf("%lld",re);
    return 0;
}
