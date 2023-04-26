#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void dfstr(char*bg,char*ed,char*buf,int idx)
{
    for(;bg!=ed;++bg)
    {
        buf[idx]=*bg;
        buf[idx+1]=0;
        puts(buf);
        dfstr(bg+1,ed,buf,idx+1);
    }
    return;
}

char*unq(char*buf)
{
    static char u[256]={'\0'};
    int hs[256]={0};
    for(int i=0,len=strlen(buf);i<len;++i)
    {
        if(hs[buf[i]]==0) hs[buf[i]]=1;
    }
    int j=0;
    for(int i=0;i<256;++i)
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
    for(int i=0;i<T;++i)
    {
        printf("case #%d:\n",i);
        char buf[256];
        scanf("%s",buf);
        char*u=unq(buf);
        char d[256];
        dfstr(u,u+strlen(u),d,0);
    }
    return 0;
}
