#include <stdio.h>
#include <stdlib.h>
int LBP(int *num);
int main()
{
    int W,H;
    scanf("%d %d",&W,&H);
    int a[100][100];
    int i,j;
    for(i=0;i<H;i++)
    {
        for(j=0;j<W;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<H-1;i++)
    {
        for(j=1;j<W-1;j++)
        {
            int num[8];
            num[0]=a[i-1][j-1];num[1]=a[i-1][j];num[2]=a[i-1][j+1];
            num[3]=a[i][j+1];num[4]=a[i+1][j+1];
            num[5]=a[i+1][j];num[6]=a[i+1][j-1];num[7]=a[i][j-1];
            int k=0;
            for(k=0;k<8;k++)
            {if(num[k]<a[i][j])num[k]=0;
            else num[k]=1;}
            printf("%d",LBP(num));
            if(j!=W-2)printf(" ");
        }
        printf("\n");
    }
}
int LBP(int *num)
{
    int i,j;
    int sum=0,cnt=256;
    for(i=0;i<8;i++)
    {
        for(j=i;j<8;j++)
        {
            sum=sum*2+num[j];
        }
        for(j=0;j<i;j++)
        {
            sum=sum*2+num[j];
        }
        if(sum<=cnt)cnt=sum;
        sum=0;
    }
    return cnt;
}
