#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strhou(char* zong,char *s)
{
    int lenzong=strlen(zong),lens=strlen(s),i,j,k,co;
    for(i=lenzong-1;i>=0;i--)
    {
        j=lens-1;
        if(s[j]==zong[i])
        {
            co=0;
            for(j=lens-1,k=i;j>=0;j--,k--)
            {
                if(s[j]==zong[k]) co++;
                else break;
            }
            if(co==lens) return &zong[i];
            else continue;

        }
    }
    return -1;
}

char* strqian(char* zong,char *s)
{
    int lenzong=strlen(zong),lens=strlen(s),i,j,k,co;
    for(i=0;i<lenzong;i++)
    {
        j=0;
        if(s[j]==zong[i])
        {
            co=0;
            for(j=0,k=i;j<lens;j++,k++)
            {
                if(s[j]==zong[k]) co++;
                else break;
            }
            if(co==lens) return &zong[i];
            else continue;

        }
    }
    return -1;
}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char zong[100],a[100],b[100];
        int re;
        scanf("%s%s%s",a,b,zong);
        char* qian=strqian(zong,a);
        qian=qian+strlen(a);
        //printf("test: qian=%d\n",qian);
        char* hou=strhou(zong,b);
        hou=hou-strlen(b);
        //printf("test: hou=%d\n",hou);
        re=hou-qian+1;
        if(hou==-1) re=0;
        else if(qian==-1) re=0;
        else if(re<1)
        {
             char* qian=strqian(zong,b);
            qian=qian+strlen(b);
            //printf("test: qian=%d\n",qian);
            char* hou=strhou(zong,a);
            hou=hou-strlen(a);
            //printf("test: hou=%d\n",hou);
            re=hou-qian+1;
        }
        if(hou==-1) re=0;
        else if(qian==-1) re=0;

        printf("case #%d:\n%d\n",i,re);

    }
    return 0;
}
