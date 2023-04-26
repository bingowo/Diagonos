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
    long long int *s1=(long long int *)a;
    long long int *s2=(long long int *)b;
    if(*s1==*s2)
    {
        return
    }
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
            scanf("%lld ",&num[i]);
            if(num[i]<0) numabs[i]=-num[i];
            else numabs[i]=num[i];
            long long int p=numabs[i];
            while(1)
            {
                if(p<10)
                {
                    c[i]=p;break;
                }
                p/=10;
            }
        }
        qsort(num,n,sizeof(num[0]),cmp);
        printf("case #%d:\n%lld",d,num[0]);
        for(i=1;i<n;i++)
        {
            printf(" %lld",num[i]);
        }
        printf("\n");
        t--;
    }
    return 0;
}