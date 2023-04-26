#include <stdio.h>
int min(int a[8])
{
    int i,j,x,n,m,t;
    m=256;
    for(i=0;i<8;i++){
        n=0;
        x=1;
        for(j=7;j>=0;j--){
            n=n+a[j]*x;
            x=x*2;
        }
        if(n<m)
            m=n;
        t=a[0];
        for(j=0;j<7;j++)
            a[j]=a[j+1];
        a[7]=t;
    }
    return m;
}
int main()
{
    int lbp[100][100];
    int a[8];
    int ij[8][2]={-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1};
    int w,h,i,j,k;
    scanf("%d%d",&w,&h);
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            scanf("%d",&lbp[i][j]);
    for(i=1;i<h-1;i++)
        for(j=1;j<w-1;j++){
            for(k=0;k<8;k++)
                if(lbp[i+ij[k][0]][j+ij[k][1]]>=lbp[i][j])
                    a[k]=1;
                else
                    a[k]=0;
            printf("%d",min(a));
            if(j==w-2)
                printf("\n");
            else
                printf(" ");
        }
    return 0;
}
