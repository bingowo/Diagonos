#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double frequency[27]={0};

int cmpfunc (const void * a, const void * b)
{
   char a0=*(char *)a;
   char b0=*(char *)b;
   int p=a0;
   int q=b0;
   //printf("fuck%c %c\n",a0,b0);
   if(p<'a')
    p=p-'A'+'a';
   if(q<'a')
    q=q-'A'+'a';
   int x=p-'a';
   int y=q-'a';
   int z=b0-a0;
    if(frequency[x]!=frequency[y])
        return (frequency[x]<frequency[y]? 1:-1);
    else if(p==q)
        return z;
    return (p-q);
}

int main()
{
    int quesnum;
    scanf("%d",&quesnum);
    for(int i=0;i<quesnum;i++)
    {
        printf("case #%d:\n",i);
        for(int i=0;i<26;i++)
            scanf("%lf",&frequency[i]);
        char s[101]={'\0'};
        scanf("%s",&s);
        qsort(s,strlen(s),sizeof(s[0]),cmpfunc);
        printf("%s\n",s);
    }
    return 0;
}
