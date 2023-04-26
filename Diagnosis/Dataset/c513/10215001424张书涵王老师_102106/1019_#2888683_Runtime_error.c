#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) //n表示球队的数量
    {
        int m;
        scanf("%d",&m); //m表示球队比赛的总场次
        int a[n+1][2];//让两列，第一列表示第几队，第二列表示积分
        int i,j;
        for(i=0;i<n+1;i++)
            a[i][0]=i;
        for(i=0;i<(n+1);i++)
            a[i][1]=0;
        int b[n+1][2];//记录每一队的胜场次（第一列）和输场次（第二列）
        for(i=0;i<(n+1);i++)
        {
            for(j=0;j<2;j++)
                b[i][j]=0;
        }
        int c[m][3];//比赛比了m场，每场有三个数字，前两个代表哪个队伍，最后一个代表谁赢
        for(i=0;i<m;i++)
        {
            for(j=0;j<3;j++)
                scanf("%d",&c[i][j]);
        }
        for(i=0;i<m;i++)  //i代表c的行数
        {
            if(c[i][2]==1)
            {
                a[c[i][0]][1]=a[c[i][0]][1]+3;
                b[c[i][0]][0]=b[c[i][0]][0]+1;
                a[c[i][1]][1]=a[c[i][1]][1]-1;
                b[c[i][1]][1]=b[c[i][1]][1]+1;
            }
            else
            {
                if(c[i][2]==0)
                {
                   a[c[i][0]][1]=a[c[i][0]][1]+1;
                   a[c[i][1]][1]=a[c[i][1]][1]+1;
                }
                else
                {
                   a[c[i][0]][1]=a[c[i][0]][1]-1;
                   b[c[i][0]][1]=b[c[i][0]][1]+1;
                   a[c[i][1]][1]=a[c[i][1]][1]+3;
                   b[c[i][1]][0]=b[c[i][1]][0]+1;
                }
            }
        }
        int d[2];
        int k;
        for(i=0;i<4;i++)
        {
            for(j=i+1;j<4;j++)
            {
                if(a[i+1][1]>a[j+1][1])
                {
                    memcpy(d,a[i+1],2*sizeof(int));
                    memcpy(a[i+1],a[j+1],2*sizeof(int));
                    memcpy(a[j+1],d,2*sizeof(int));
                }
                else
                {
                    if(a[i+1][1]==a[j+1][1])
                    {
                        if(b[a[i+1][0]][0]<b[a[j+1][0]][0])
                        {
                            memcpy(d,a[i+1],2*sizeof(int));
                            memcpy(a[i+1],a[j+1],2*sizeof(int));
                            memcpy(a[j+1],d,2*sizeof(int));
                        }
                        else
                        {
                            if(b[a[i+1][0]][0]==b[a[j+1][0]][0])
                            {
                                if(b[a[i+1][0]][1]>b[a[j+1][1]][1])
                                {
                                    memcpy(d,a[i+1],2*sizeof(int));
                                    memcpy(a[i+1],a[j+1],2*sizeof(int));
                                    memcpy(a[j+1],d,2*sizeof(int));
                                }
                                else
                                {
                                    if(b[a[i+1][0]][1]==b[a[j+1][1]][1])
                                    {
                                        if(a[i+1][0]>a[j+1][0])
                                        {
                                            memcpy(d,a[i+1],2*sizeof(int));
                                            memcpy(a[i+1],a[j+1],2*sizeof(int));
                                            memcpy(a[j+1],d,2*sizeof(int));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for(k=1;k<(n+1);k++)
            printf("%d ",a[k][0]);
        printf("\n");
    }
}
