#include<stdio.h>
#include<math.h>

int f[12][1010];
int w[12];
int cmp(const void *a,const void *b)
{
    int a1=*(int *)a,b1=*(int *)b;
    return a1>b1?-1:1;
}
int main()
{
    int n;scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    qsort(w,n,sizeof(int),cmp);
    f[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            f[i+1][j]=f[i][j];
            if(j-w[i]>=0)f[i+1][j]|=f[i][j-w[i]];
            if(j+w[i]<=sum)f[i+1][j]|=f[i][j+w[i]];
        }
    }
    for(int i=1;i<=sum;i++)printf("%d",f[n-1][i]);
    return 0;
}
