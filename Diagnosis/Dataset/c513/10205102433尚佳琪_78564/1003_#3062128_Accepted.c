#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    long long int num;
    int cnt;
}NODE;
int cmp(const void *a,const void *b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    if(s1.cnt!=s2.cnt)
        return s2.cnt-s1.cnt;
    else{
        if(s1.num>s2.num)
            return 1;
        else return 0;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        NODE a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i].num);
           // printf("%lld ",a[i].num);
            a[i].cnt=0;
            long long temp=a[i].num;
            for(int j=0;j<64;j++)
            {
                if((1&temp)==1)
                {
                    a[i].cnt+=1;
                }
                temp=temp>>1;
            }

        }
        qsort(a,n,sizeof(a[i]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("%lld ",a[i].num);
        printf("\n");
    }
    return 0;
}
