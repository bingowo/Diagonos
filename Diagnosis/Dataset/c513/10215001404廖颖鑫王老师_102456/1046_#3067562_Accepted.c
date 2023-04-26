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
    if(strcmp(x,"the")==0) return -1;
    else if(strcmp(x,"The")==0) return -1;
    else if(strcmp(x,"tHe")==0) return -1;
    else if(strcmp(x,"thE")==0) return -1;
    else if(strcmp(x,"THe")==0) return -1;
    else if(strcmp(x,"ThE")==0) return -1;
    else if(strcmp(x,"tHE")==0) return -1;
    else if(strcmp(x,"THE")==0) return -1;

    else if (strcmp(x,"a")==0) return -1;
    else if (strcmp(x,"A")==0) return -1;

    else if (strcmp(x,"an")==0) return -1;
    else if (strcmp(x,"An")==0) return -1;
    else if (strcmp(x,"aN")==0) return -1;
    else if (strcmp(x,"AN")==0) return -1;

    else if (strcmp(x,"and")==0) return -1;
    else if (strcmp(x,"And")==0) return -1;
    else if (strcmp(x,"aNd")==0) return -1;
    else if (strcmp(x,"anD")==0) return -1;
    else if (strcmp(x,"ANd")==0) return -1;
    else if (strcmp(x,"AnD")==0) return -1;
    else if (strcmp(x,"aND")==0) return -1;
    else if (strcmp(x,"AND")==0) return -1;

    else if (strcmp(x,"of")==0) return -1;
    else if (strcmp(x,"Of")==0) return -1;
    else if (strcmp(x,"oF")==0) return -1;
    else if (strcmp(x,"OF")==0) return -1;

    else if (strcmp(x,"for")==0) return -1;
    else if (strcmp(x,"For")==0) return -1;
    else if (strcmp(x,"fOr")==0) return -1;
    else if (strcmp(x,"foR")==0) return -1;
    else if (strcmp(x,"FOr")==0) return -1;
    else if (strcmp(x,"FoR")==0) return -1;
    else if (strcmp(x,"fOR")==0) return -1;
    else if (strcmp(x,"FOR")==0) return -1;

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