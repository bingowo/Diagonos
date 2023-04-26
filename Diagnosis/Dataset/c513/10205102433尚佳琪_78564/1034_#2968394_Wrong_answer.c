#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    else//可能有频率相同但是字母不同的情况 和 大小写情况
    {
        if((s1-s2)==32)//如果是大小写情况
            return s2-s1;
        else
            return s1-s2;//如果不是大小写情况
        
    }
    //return s2-s1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        for(int i=0;i<26;i++)
        {
            scanf("%lf",&p['A'+i]);
            p['a'+i]=p['A'+i];
        }
        char s[1000];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }

    return 0;
}
