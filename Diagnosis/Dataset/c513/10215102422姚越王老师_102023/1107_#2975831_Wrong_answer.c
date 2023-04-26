#include<stdio.h>
int main()
{
    int T,i,j,oper[5][5];scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        for(i=0;i<5;++i)
            for(j=0;j<5;++j)oper[i][j]=0;
        for(i=1;i<4;++i)
            for(j=1;j<4;++j)scanf("%d",&oper[i][j]);
        int a[5][5];
        for(i=1;i<4;++i)
        {
            for(j=1;j<4;++j)
            {
                a[i][j]=oper[i-1][j]+oper[i][j]+oper[i][j-1]+oper[i][j+1]+oper[i+1][j];
                if(a[i][j]%2)a[i][j]=0;
                else a[i][j]=1;
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}