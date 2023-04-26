#include <stdio.h>
#include <stdlib.h>

int r,c,n,k;

void contain_k1_or_not(int rlenth,int clenth,int*num_k1,int a[][100])
{
    int i,j;
    for(i=0;(i+clenth-1)<c;i++)
    {
        for(j=0;(j+rlenth-1)<r;j++)
        {
            int x,y,lenth=0;
            for(x=i;x<(i+clenth);x++)
            {
                for(y=j;y<(j+rlenth);y++)
                {
                    if(a[y][x]==1)
                        lenth=lenth+1;
                }
            }
            if(lenth>=k)
                num_k1[0]++;
        }
    }
}

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int a[100][100]={0};
        int i,x,y;
        int num_k1[1]={0};//含有k个1的矩阵的数量
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            a[x-1][y-1]=1;
        }
        int r_lenth,c_lenth;
        for(r_lenth=1;r_lenth<=r;r_lenth++)
        {
            for(c_lenth=1;c_lenth<=c;c_lenth++)//暴力枚举
                contain_k1_or_not(r_lenth,c_lenth,num_k1,a);
        }
        printf("case #%d:\n",question_num);
        printf("%d\n",num_k1[0]);
    }
}