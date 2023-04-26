#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    long long int num;
    long long int numabs;
    long  long int c;
}sort;
int cmp(const void *a,const void *b)
{
    sort *s1=(sort *)a;
    sort *s2=(sort *)b;
    if(s1->c==s2->c)
    {
        return s1->num>s2->num?1:-1;
    }
    return s2->c-s1->c;
}
int main()
{
    int t,d=0;
    scanf("%d\n",&t);
    while(t>0)
    {
        int n,i=0;
        scanf("%d\n",&n);
        sort k[10000];
        for(i=0;i<n;i++)
        {
            scanf("%lld ",&k[i].num);
            if(k[i].num<0) k[i].numabs=-k[i].num;
            else k[i].numabs=k[i].num;
            long long int p=k[i].numabs;
            while(1)
            {
                if(p<10)
                {
                    k[i].c=p;break;
                }
                p/=10;
            }
        }
        qsort(k,n,sizeof(k[0]),cmp);
        printf("case #%d:\n%lld",d,k[0].num);
        for(i=1;i<n;i++)
        {
            printf(" %lld",k[i].num);
        }
        printf("\n");
        t--;
        d++;
    }
    return 0;
}