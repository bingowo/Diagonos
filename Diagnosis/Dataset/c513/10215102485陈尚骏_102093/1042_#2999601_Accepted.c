#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void dfstr(char*bgn,char*end,char*buf,int buf_idx)
{
    for(;bgn!=end;bgn++)
    {
        buf[buf_idx]=*bgn;
        buf[buf_idx+1]=0;
        puts(buf);
        dfstr(bgn+1,end,buf,buf_idx+1);
    }
}

char*unq(char*buf)
{
    static char u[256];
    int hs[256]={0};
    memset(u,0,sizeof(u));
    for(int i=0,len=strlen(buf);i<len;i++)
    {
        if(hs[buf[i]]==0) hs[buf[i]]=1;
    }
    int j=0;
    for(int i=0;i<256;i++)
    {
        if(hs[i]!=0) u[j++]=i;
    }
    u[j]=0;
    return u;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char buf[256];
        scanf("%s",buf);
        char*m=unq(buf);
        printf("case #%d:\n",i);
        char dfs_buf[256];
        dfstr(m,m+strlen(m),dfs_buf,0);
    }
    return 0;
}
