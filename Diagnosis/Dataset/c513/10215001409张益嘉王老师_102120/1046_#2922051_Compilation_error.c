#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int splitstring(char zong[],char sign,char* fen[],int maxn)
{
    int len=strlen(zong),k,co=0;

    fen[co++]=zong;
    for(k=0;k<len;k++)
    {
        if(zong[k]==sign)
        {
            zong[k]=0;
            fen[co++]=&zong[k+1];
            if(co>=maxn) break;
        }

    }
    return co;
}

int judge(char x[])
{
    int re;
    if(stricmp(x,"the")==0) return -1;
    else if (stricmp(x,"a")==0) return -1;
    else if (stricmp(x,"an")==0) return -1;
    else if (stricmp(x,"and")==0) return -1;
    else if (stricmp(x,"of")==0) return -1;
    else if (stricmp(x,"for")==0) return -1;
    else return 1;


}

int main()
{
    char c[10];
    int t,i;
    gets(c);
    t=atoi(c);
    for(i=0;i<t;i++)
    {
        char s[200];
        char *word[120];
        int co,sum=0,j;
        gets(s);
        co=splitstring(s,' ',word,120);
        for(j=0;j<co;j++)
        {
            if(judge(word[j])==1) sum++;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
}
