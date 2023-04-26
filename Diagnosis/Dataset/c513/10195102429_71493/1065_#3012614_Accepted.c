#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int sum[21],up[21],down[21];
    sum[1]=a;up[1]=a;down[1]=0;
    sum[2]=a;
    for(int t=0;t<=m;t++){
        up[2]=t;down[2]=t;
        for(int i=3;i<n;i++){
            up[i]=up[i-1]+up[i-2];
            down[i]=up[i-1];
            sum[i]=sum[i-1]+up[i]-down[i];
        }
        if(sum[n-1]==m){
            printf("%d\n",sum[x]);
    }
    }
    return 0;
}
