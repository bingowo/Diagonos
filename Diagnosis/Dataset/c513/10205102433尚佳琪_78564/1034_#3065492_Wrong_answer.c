#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double p[128]={0.0};

int cmp(const void *a,const void *b)
{
    char s1=*(char*)a;
    char s2=*(char*)b;
    if(p[s1]!=p[s2])
    {
        if(p[s1]>p[s2])
            return -1;
        else
            return 1;
    }
    else
    {
        return s2-s1;
    }
}

int main()
{
   int t;
   scanf("%d\n",&t);
   for(int i=0;i<t;i++)
   {
        for(int i=0;i<26;i++)
        {
            double b;
            scanf("%lf",&b);
            p['A'+i]=b;
            p['a'+i]=b;
        }
        char a[150];
        scanf("%s",a);
        int len=strlen(a);
        qsort(a,len,sizeof(a[0]),cmp);
        printf("%s\n",a);
   }
}
