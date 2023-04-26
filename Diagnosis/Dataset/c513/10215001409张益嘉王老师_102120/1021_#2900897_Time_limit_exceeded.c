#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int as[128];


int splitstring(char zong[],char sign,char* fen[],int maxn)
{
    int len,i,co=0;
    len=strlen(zong);
    fen[co++]=zong;
    for(i=0;i<len;i++)
    {
        if(zong[i]==sign)
        {
            zong[i]=0;
            fen[co++]=&zong[i+1];
            if(co>=maxn) break;
        }

    }
    return co;

}

void createorder(char order[],int as[])
{
    int len=strlen(order),i;
    for(i=0;i<len;i++)
    {
        as[order[i]]=i;
        as[order[i]+32]=i;
    }
}

int cmp(const void*a,const void* b)
{
    char* aa=*(char**)a;
    char* bb=*(char**)b;
    int lena=strlen(aa);
    int lenb=strlen(bb);
    int small;
    if(lena>=lenb) small=lena;
    else small=lenb;
    int i,j;
    for (i=0;i<small;i++)
    {
        if(as[aa[i]]<as[bb[i]]) return -1;
        else if(as[aa[i]]>as[bb[i]]) return 1;
        else continue;
    }
    if (i==small)
    {
        if(lena>lenb) return 1;
        else return -1;
    }

}

int main()
{
    while(1)
    {
        memset(as,0,128*sizeof(int));
        char order[30];
        gets(order);
        int len=strlen(order);
        if (len==0) break;
        //if(strcmp(order,"\n")==0) break;
        createorder(order,as);
        /*for(int j=0;j<128;j++)
        {
            printf("as[%d]=%d\n",j,as[j]);
        }*/
        char sen[1000];
        char* word[100];
        gets(sen);
        int maxn=100,co=0,i;
        co=splitstring(sen,' ',word,maxn);
        /*for(i=0;i<co;i++)
        {
            printf("word[%d]=%s\n",i,word[i]);
        }*/
        qsort(word,co,sizeof(char*),cmp);
        for(i=0;i<co-1;i++)
        {
            printf("%s ",word[i]);
        }
       printf("%s",word[i]);
       printf("\n");

    }
    return 0;
}
