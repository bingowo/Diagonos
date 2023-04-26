#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* s=(char*)malloc(sizeof(char)*1000010);
    gets(s);
    char re[100];
    memset(re,0,100*sizeof(char));
    int i,t=0,len,co=0,st;
    int m[128];
    memset(m,-1,128*sizeof(int));
    len=strlen(s);
    for(i=0;i<len;i++)
    {
       if(m[s[i]]>=t)
       {
           t=m[s[i]]+1;
           m[s[i]]=i;
       }
       else
       {
           m[s[i]]=i;
           if(co<i-t+1)
           {
               st=t;
               co=i-t+1;
           }
       }
    }
    for(i=0;i<co;i++)
    {
        printf("%c",s[st+i]);
    }
    printf("\n");
    return 0;

}
