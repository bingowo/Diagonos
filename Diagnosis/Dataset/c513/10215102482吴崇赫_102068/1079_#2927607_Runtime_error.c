#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4005
#define M 25

int cmp(const void* a,const void* b)
{
    return *(int*)a>*(int*)b?1:-1;
}

int main()
{
    int T;scanf("%d\n",&T);
    for(int i=0;i<T;++i){
        int num[N];int test[M][3];int sum[N];
        for(int i=0;i<N;++i)num[i]=sum[i]=0;
        for(int i=0;i<M;++i){
            for(int j=0;j<3;++j)test[i][j]=0;
        }
        int n,m;int ps=0,flag=0;
        scanf("%d %d\n",&n,&m);
        for(int i=0;i<n;++i)scanf("%d",&num[i]);
        for(int i=0;i<m;++i)scanf("%d%d",&test[i][0],&test[i][1]);
        for(int i=1;i<=n;++i){    //有几个数字相加
            for(int j=0;j<n;++j){
                flag=0;
                for(int k=j;k<i+j&&i+j<=n;++k){
                    sum[ps]+=num[k];
                    flag=1;
                }
                if(flag)ps++;
            }
        }
        qsort(sum,ps,sizeof(sum[0]),cmp);
        //for(int i=0;i<ps;++i)printf("%d ",sum[i]);
        int ret[M];int pr=0;
        for(int i=0;i<M;++i)ret[i]=0;
        for(int i=0;i<m;++i){
            for(int j=test[i][0]-1;j<=test[i][1]-1;++j){
                ret[pr]+=sum[j];
            }
            pr++;
        }
        printf("case #%d:\n",i);
        for(int i=0;i<pr;++i)printf("%d\n",ret[i]);
    }
    return 0;
}