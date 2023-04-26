#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    return (*(int *)a)-(*(int *)b);
}
int main()
{
    int T,num = 0,i,j,p,k = 0,q;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int n,m;
        k = 0;
        scanf("%d %d",&n,&m);
        int a[n],b[500000]= {0};
        for(j = 0;j<n;j++)
            scanf("%d",&a[j]);
        for(q = 0;q<j;q++)
        {
            for(p = 0;p<j-q;p++)
                {
                    int P = p;
                    //printf("%d ",a[P]);
                    num = 0;
                    while(num<=q)
                    {b[k] = b[k] + a[P];
                    P++;
                    num++;}
                    k++;
                    //printf("%d\n",b[k-1]);
                }
        }
        qsort(b,k,sizeof(int),cmp);
        //for(j = 0;j<k;j++)
            //printf("%d %d\n",b[j],k);
        printf("case #%d:\n",i);
        for(j = 0;j<m;j++)
        {
            int L,U;
            scanf("%d %d",&L,&U);
            int ans = 0;
            for(q = L-1;q<U;q++)
                ans += b[q];
            printf("%d\n",ans);
        }
    }
    return 0;
}
