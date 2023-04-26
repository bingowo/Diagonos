#include<stdio.h>
int light[3][3]={0};
int T;
const int dx[5]={0,0,0,-1,1};
const int dy[5]={0,1,-1,0,0};
void operate(int x,int y)
{
    for(int d=0;d<5;d++)
    {
        int x1=x+dx[d],y1=y+dy[d];
        if(x1>=0 && x1<3 && y1>=0 && y1<3) light[x1][y1]=1-light[x1][y1];
    }
    return 0;
}
int main(void)
{
    
    scanf("%d\n",&T);
    for(int step=0;step<T;step++)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                light[i][j]=1;
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int p;
                scanf("%d ",&p);
                if(p%2==1) operate(i,j);
            }
        }
        printf("case #%d:\n",step);
        for(int i=0;i<3;i++)
        {
            
            for(int j=0;j<3;j++)
            {
                printf("%d ",light[i][j]);
            }    
            printf("\n");
        }
    }
    return 0;
}