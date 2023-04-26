#include <stdio.h>
#include <math.h>

int ans[100][100];
int res[100][100];

void solve(int i,int j)
{
    int val[8]={ans[i-1][j-1],ans[i-1][j],ans[i-1][j+1],ans[i][j+1],ans[i+1][j+1],ans[i+1][j],ans[i+1][j-1],ans[i][j-1]};
    int cnt=1,min=255,sum=0;
    for(int m=0;m<8;m++)
    {
        if(val[m]<ans[i][j])
            val[m]=0;
        else
            val[m]=1;
    }
    int q=0;
    for(int k=0;q<8;q++)
    {
        k=q;
        cnt=0;
        sum=0;
        while(1)
        {
            if(cnt==8)
                break;
            if(k==8)
                k=0;
            sum=sum+pow(2,cnt)*val[k];
            cnt++;
            k++;
        }
        if(sum<min)
            min=sum;
    }
    res[i][j]=min;
}

int main()
{
    int W,H;
    scanf("%d %d",&W,&H);
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            scanf("%d",&ans[i][j]);
    for(int i=1;i<H-1;i++)
        for(int j=1;j<W-1;j++)
        {
            solve(i,j);
        }
    for(int i=1;i<H-1;i++)
    {
        for(int j=1;j<W-1;j++)
        {
            if(j==1)
                printf("%d",res[i][j]);
            else
                printf(" %d",res[i][j]);
        }
        printf("\n");
    }
//    for(int i=0;i<H;i++)
//    {
//        for(int j=0;j<W;j++)
//        {
//            if(j==0)
//                printf("%d",ans[i][j]);
//            else
//                printf(" %d",ans[i][j]);
//        }
//        printf("\n");
//    }
}
