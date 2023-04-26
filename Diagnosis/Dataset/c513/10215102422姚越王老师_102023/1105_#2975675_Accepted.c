#include<stdio.h>
#define C 110
void print(int (*b)[3])
{
    int base=b[1][1],i,j,a[8],tmp[8],ans=0,weight=1,ans_arr[8];
    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
        {
            if(b[i][j]<base)b[i][j]=0;
            else b[i][j]=1;
        }
    a[0]=b[0][0];a[1]=b[0][1];a[2]=b[0][2];a[3]=b[1][2];
    a[4]=b[2][2];a[5]=b[2][1];a[6]=b[2][0];a[7]=b[1][0];
    for(i=0;i<8;++i)//从a[i]开始
    {
        for(j=0;j<8;++j)tmp[j]=a[(j+i)%8];
        weight=1;ans=0;
        for(j=7;j>-1;--j){ans+=tmp[j]*weight;weight*=2;}
        ans_arr[i]=ans;
    }
    for(i=0;i<8;++i)if(ans_arr[i]<ans)ans=ans_arr[i];
    printf("%d ",ans);
    return;
}
int main()
{
    int W,H,a[C][C],i,j;scanf("%d %d\n",&W,&H);
    for(i=0;i<H;++i)
        for(j=0;j<W;++j)scanf("%d",&a[i][j]);
    for(i=1;i<H-1;++i)
    {
        for(j=1;j<W-1;++j)
        {
            int b[3][3];
            b[0][0]=a[i-1][j-1];b[0][1]=a[i-1][j];b[0][2]=a[i-1][j+1];
            b[1][0]=a[i][j-1];b[1][1]=a[i][j];b[1][2]=a[i][j+1];
            b[2][0]=a[i+1][j-1];b[2][1]=a[i+1][j];b[2][2]=a[i+1][j+1];
            print(b);
        }
        printf("\n");
    }
    return 0;
}