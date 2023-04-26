#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char str[21];
    int sum;
}data;

int cmp(const void *a,const void *b)
{
    data *s1=(data*)a,*s2=(data*)b;
    if(s1->sum==s2->sum) return strcmp(s1->str,s2->str);
    else return s2->sum-s1->sum;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        data Dt[n];
        for(int j=0;j<n;j++)
        {
            scanf("%s",Dt[j].str);
            Dt[j].sum=0;
            int len=strlen(Dt[j].str);
            int cd[26]={0};
            for(int k=0;k<len;k++)
            {
                if(cd[Dt[j].str[k]-'A']==0)
                {
                    cd[Dt[j].str[k]-'A']++;
                    Dt[j].sum++;
                }
            }
        }
        qsort(Dt,n,sizeof(data),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
            printf("%s\n",Dt[j].str);
    }
    return 0;
}
