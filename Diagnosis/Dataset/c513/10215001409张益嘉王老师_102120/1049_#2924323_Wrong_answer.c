#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int splitstring(char zong[],char sign[],char* fen[],int maxn)
{
    int len,co=0,i,n,j;
    len=strlen(zong);
    n=strlen(sign);
    fen[co++]=&zong;
    for(i=0;i<len;i++)
    {
        for(j=0;j<n;j++)
        {
            if(zong[i]==sign[j])
            {
                zong[i]=0;
                fen[co++]=&zong[i+1];
                break;
            }
        }
        if(co>=maxn) break;
    }
    return co;
}

int cmp(const void*a,const void*b)
{
    char* aa=*((char**)a);
    char* bb=*((char**)b);

    return strcmp(aa,bb);

}

int main()
{
     int i,t;
     char tt[10];
     gets(tt);
     t=atoi(tt);
     for(i=0;i<t;i++)
     {
         char s[600];
         memset(s,0,600*sizeof(char));
         gets(s);
         char flag[10];
         memset(flag,0,10*sizeof(char));
         char *word[510];
         int co,j;

         strcpy(flag,", .?!");
         co=splitstring(s,flag,word,500);
         qsort(word,co,sizeof(char*),cmp);
         printf("case #%d:\n",i);
         for(j=0;j<co-1;j++)
         {
             if((strcmp(word[j],word[j+1])!=0)&&(strlen(word[j])>0)) printf("%s ",word[j]);
         }
         printf("%s\n",word[j]);

     }
     return 0;

}
