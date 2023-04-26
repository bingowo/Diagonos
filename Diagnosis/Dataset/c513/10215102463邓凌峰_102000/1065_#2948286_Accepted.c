#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int up[21],down[21],rest[21];
    up[1]=a;down[1]=0;rest[1]=a;
    for(int i=0;i<m;i++){
        up[2]=i;down[2]=i;rest[2]=a;
        for(int j=3;j<n;j++){
            up[j]=up[j-1]+up[j-2];
            down[j]=up[j-1];
            rest[j]=rest[j-1]+up[j]-down[j];
        }
        if(rest[n-1]==m) printf("%d",rest[x]);

    }
}
