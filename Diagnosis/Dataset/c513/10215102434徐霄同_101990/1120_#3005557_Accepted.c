#include <stdio.h>
int f(int i,int j,int i0,int j0,int a[10][10])
{
    int x,y,n;
    n=0;
    for(x=i;x<=i0;x++)
        for(y=j;y<=j0;y++)
            if(a[x][y]==1)
                n++;
    return n;
}
int main()
{
    int a[10][10];
    int r,c,n,k,x,y,i,j,i0,j0,t,t0,n0;
    scanf("%d",&t);
    for(t0=0;t0<t;t0++){
        scanf("%d%d%d%d",&r,&c,&n,&k);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                a[i][j]=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            a[x-1][y-1]=1;
        }
        n0=0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                for(i0=i;i0<r;i0++)
                    for(j0=j;j0<c;j0++)
                        if(f(i,j,i0,j0,a)>=k){
                            n0=n0+(c-j0);
                            break;
                        }
        printf("case #%d:\n",t0);
        printf("%d\n",n0);
    }
    return 0;
}
