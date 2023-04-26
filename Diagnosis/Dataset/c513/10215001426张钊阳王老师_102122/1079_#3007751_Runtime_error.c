#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cmp(const void *a1,const void *b1);
    int T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        int n,m;

        scanf("%d %d",&n,&m);
        int ori[1002];
        for(int i=0;i<n;i++)
            scanf("%d",&ori[i]);


        int ans[1002]={0};//得出的若干项和的结果 储存在这个数组中 先放进来再qsort
        int k=0;//k是ans中的位置
        for(int i=0;i<n;i++)
        {
            int sum[1002]={0};
            for(int t=i,j=0;j<=n-i-1;j++)
            {
                if(j==0) {sum[j]=ori[t+j];}
                else if(j!=0) {sum[j]=sum[j-1]+ori[t+j];}
                ans[k]=sum[j];
                k++;
            }
        }
        int cnt=n*(n+1)/2;

        qsort(ans,cnt,sizeof(int),cmp);

        for(int q=0;q<cnt;q++)
            printf("%d ",ans[q]);

        int  L[22];
        int U[22];
        for(int z=0;z<m;z++)
            scanf("%d %d",&L[z],&U[z]);

        printf("case #%d:\n",z);

        for(int p=0;p<m;p++)
        {
            int sum=0;
            for(int t=L[p]-1;t<=U[p]-1;t++)
                sum+=ans[t];
            printf("%d",sum);
            printf("\n");
        }
    }
    return 0;
}


int cmp(const void *a1,const void *b1)
{
    int a=*(int *)a1;
    int b=*(int *)b1;
    if(a>=b) return 1;
    else return -1;
}
