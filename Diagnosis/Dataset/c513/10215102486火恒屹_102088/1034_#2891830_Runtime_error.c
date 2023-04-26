#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float frequency[27]={0};

int cmpfuncup (const void * a, const void * b)
{
   char *a0=(char *)a;
   char *b0=(char *)b;
   char *a1=a0;
   char *b1=b0;
   if(a0<'a')
    a1=a1-'A'+'a';
   if(b0<'a')
    b1=b1-'A'+'a';
   int x=a1-'a';
   int y=b1-'a';
    if(b1!=a1)
        return frequency[x]-frequency[y];
    else return b0-a0;
   return 0;
}

int main()
{
    int quesnum;
    scanf("%d",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        for(int i=0;i<26;i++)
            scanf("%f",&frequency[i]);
        char s[101]={'\0'};
        scanf("%s",&s);
        qsort(s,strlen(s),sizeof(s[0]),cmpfuncup);
        printf("%s\n",s);
    }
    return 0;
}
