#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int sum;
    char s[21];
}str;

int cmp(const void*a,const void*b)
{
    str*a1=(str*)a;
    str*b1=(str*)b;
    if(a1->sum==b1->sum) return strcmp(a1->s,b1->s);
    else return b1->sum-a1->sum;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        int n;
        scanf("%d",&n);
        str cs[n];
        for(int j=0;j<n;++j)
        {
            scanf("%s",cs[j].s);
            cs[j].sum=0;
            int len=strlen(cs[j].s);
            int a[26]={0};
            for(int k=0;k<len;++k)
            {
                if(a[cs[j].s[k]-'A']==0)
                {
                    cs[j].sum++;
                    a[cs[j].s[k]-'A']++;
                }
            }
        }
        qsort(cs,n,sizeof(str),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;++j)
        {
            printf("%s\n",cs[j].s);
        }
    }
    return 0;
}
