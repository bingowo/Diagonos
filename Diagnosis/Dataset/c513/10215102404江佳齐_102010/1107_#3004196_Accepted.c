#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        int table[3][3],ct[3][3];
        int i,j,m;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                scanf("%d",&ct[i][j]);
        }
        printf("case #%d:\n",k);
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                table[i][j]=1;//初始化为亮
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                for(m=0;m<ct[i][j];m++)
                {
                    table[i][j]*=-1;
                    if((i-1)>=0) table[i-1][j]*=-1;
                    if((i+1)<=2) table[i+1][j]*=-1;
                    if((j-1)>=0) table[i][j-1]*=-1;
                    if((j+1)<=2) table[i][j+1]*=-1;
                }
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(table[i][j]==-1) table[i][j]=0;
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<2;j++)
                printf("%d ",table[i][j]);
            printf("%d\n",table[i][j]);
        }
    }

    return 0;
}
