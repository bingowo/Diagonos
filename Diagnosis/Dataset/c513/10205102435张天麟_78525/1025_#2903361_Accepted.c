#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
    char s[21];
    int num;
}str;
int cmp(const void *a,const void *b)
{
    int numa=((str*)a)->num,numb=((str*)b)->num;
    if(numa!=numb)return numb-numa;
    else return strcmp(((str*)a)->s,((str*)b)->s);
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n,j;
        scanf("%d",&n);
        str ss[n];
        for(j=0;j<n;j++)
        {
            scanf("%s",ss[j].s);
            int used[128];
            int k,sum=0,len=strlen(ss[j].s);
            for(k=0;k<128;k++)
            {
                used[k]=-1;
            }
            for(k=0;k<len;k++)
            {
                char c=ss[j].s[k];
                if(used[c]==-1)
                {
                    used[c]=0;
                    sum++;
                }
            }
            ss[j].num=sum;
        }
        qsort(ss,n,sizeof(ss[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%s\n",ss[j].s);
        }
    }
    return 0;
}
