#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int wei;
    int shu[500];
}bigint;

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

bigint cheng(bigint a,int mid)
{
    int jin=0,i,c;
    for(i=0;(i<a.wei)||(jin!=0);i++)
    {
        c=a.shu[i]*mid+jin;
        a.shu[i]=c%10;
        jin=c/10;
    }
    a.wei=i;
    //for(i=0;i<a.wei;i++) printf("a.shu[%d]=%d\n",i,a.shu[i]);
    return a;
}

bigint reverse(bigint a)
{
    int i,c;
    for(i=0;i<(a.wei/2);i++)
    {
        c=a.shu[i];
        a.shu[i]=a.shu[a.wei-i-1];
        a.shu[a.wei-1-i]=c;
    }
    return a;
}

int main()
{
    char s[1010];
    scanf("%s",s);
    int i,len,mid;
    bigint a;
    memset(a.shu,0,sizeof(int)*500);
    a.shu[0]=1;
    a.wei=1;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        mid=zhongshu(s,i);
        a=cheng(a,mid);
        //printf("[%d]=%d\n",i,mid);
    }
    //for(i=0;i<a.wei;i++) printf("(%d)",a.shu[i]);
    a=reverse(a);

    for(i=0;i<a.wei;i++) printf("%d",a.shu[i]);
    return 0;
}
