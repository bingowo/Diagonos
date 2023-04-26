#include <stdio.h>
#include <stdlib.h>


int mul(int(*p)[120],int x,int y,int m)
{
    if(m<=p[y][x])return 1;
    else return 0;
}

int main()
{
    int num[120][120];
    int r,c;
    scanf("%d%d",&c,&r);
    for(int i =0;i<r;i++)
    {
        for(int m=0;m<c;m++)
        {
            scanf("%d",&num[i][m]);
        }
    }
    for(int y=1;y<r-1;y++)
    {
        for(int x=1;x<c-1;x++)
        {  int p[8];

            int min =256;
            p[0] = mul(num,x-1,y-1,num[y][x]);
            p[1] = mul(num,x,y-1,num[y][x]);
            p[2] = mul(num,x+1,y-1,num[y][x]);
            p[3] = mul(num,x+1,y,num[y][x]);
            p[4] = mul(num,x+1,y+1,num[y][x]);
            p[5] = mul(num,x,y+1,num[y][x]);
            p[6] = mul(num,x-1,y+1,num[y][x]);
            p[7] = mul(num,x-1,y,num[y][x]);
            for(int i =0;i<8;i++)
            {
                int res = 0;
                for(int k =i;k<i+8;k++)
                {
                    res*=2;
                    res+=p[k%8];
                }
                min =(min>res)?res:min;
            }
            printf("%d ",min);
        }
        printf("\n");

    }
    return 0;
}
