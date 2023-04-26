#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int splitstring(char*zong,char*fen[])
{
    int len=strlen(zong);
    int i,co=0;
    for(i=0;i<len;i++)
    {
        if(((zong[i]<='9')&&(zong[i]>='0'))||((zong[i]>='a')&&(zong[i]<='f'))||(zong[i]=='x')) continue;
        else zong[i]=0;
    }
    for(i=0;i<len;i++)
    {
        if(zong[i]=='x')
        {
            if((zong[i-1]=='0')&&(i>0))
            {

                zong[i]=0;
                fen[co]=&zong[i+1];
                if(strlen(fen[co])<=0) co--;
                co++;
            }
            else zong[i]=0;
        }

    }
    return co;

}

unsigned int tran(char x[])
{
    int len=strlen(x),i;
    unsigned int re=0;
    int a[110000];
    for(i=0;i<len;i++)
    {
        if((x[i]<='9')&&(x[i]>='0')) a[i]=x[i]-'0';
        else a[i]=x[i]-'a'+10;
    }
    /*for(i=0;i<len;i++)
    {
        printf("test a[%d]=%u\n",i,a[i]);
    }*/
    for(i=0;i<len;i++)
    {
        re*=16;
        re=(unsigned int)a[i]+re;
    }
//printf("test re=%u\n",re);
    return re;

}

int main()
{
    char *s;
    s=(char*)malloc(sizeof(char)*110000);
    char*num[110000];
    int co,i;
    scanf("%s",s);
    co=splitstring(s,num);
    /*for(i=0;i<co;i++)
    {
        printf("test  num[%d]=%s\n",i,num[i]);
    }*/
    //unsigned int *re=(unsigned int*)malloc(sizeof(unsigned int)*co);
    unsigned int re[110000];
    memset(re,0,sizeof(unsigned)*110000);
    if (co==0) printf("%d",-1);
    else
    {
        for(i=0;i<co;i++)
        {
            re[i]=tran(num[i]);
        }

    for(i=0;i<co-1;i++)
    {
        printf("%u ",re[i]);
    }
    printf("%u\n",re[i]);
    }
    return 0;
}
