#include <stdio.h>
#include <string.h>


int main()
{
    int T;
    int a[3][3];
    int k;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j]=1;
        printf("case #%d:\n",i);
        for(int m=0;m<3;m++)
            for(int n=0;n<3;n++)
            {
                scanf("%d",&k);
                if(k%2==1)
                {
                    if(m==0 && n==0)
                    {
                        a[m][n]=1-a[m][n];
                        a[1][0]=1-a[1][0];
                        a[0][1]=1-a[0][1];
                    }
                    else if(m==0 && n==1)
                    {
                        a[m][n]=1-a[m][n];
                        a[0][0]=1-a[0][0];
                        a[0][2]=1-a[0][2];
                        a[1][1]=1-a[1][1];
                    }
                    else if(m==0 && n==2)
                    {
                        a[m][n]=1-a[m][n];
                        a[1][2]=1-a[1][2];
                        a[0][1]=1-a[0][1];
                    }
                    else if(m==1 && n==0)
                    {
                        a[m][n]=1-a[m][n];
                        a[0][0]=1-a[0][0];
                        a[1][1]=1-a[1][1];
                        a[2][0]=1-a[2][0];
                    }
                    else if(m==1 && n==1)
                    {
                        a[m][n]=1-a[m][n];
                        a[0][1]=1-a[0][1];
                        a[1][0]=1-a[1][0];
                        a[1][2]=1-a[1][2];
                        a[2][1]=1-a[2][1];
                    }
                    else if(m==1 && n==2)
                    {
                        a[m][n]=1-a[m][n];
                        a[1][1]=1-a[1][1];
                        a[0][2]=1-a[0][2];
                        a[2][2]=1-a[2][2];
                    }
                    else if(m==2 && n==0)
                    {
                        a[m][n]=1-a[m][n];
                        a[1][0]=1-a[1][0];
                        a[2][1]=1-a[2][1];
                    }
                    else if(m==2 && n==1)
                    {
                        a[m][n]=1-a[m][n];
                        a[2][0]=1-a[2][0];
                        a[1][1]=1-a[1][1];
                        a[2][2]=1-a[2][2];
                    }
                    else
                    {
                        a[m][n]=1-a[m][n];
                        a[1][2]=1-a[1][2];
                        a[2][1]=1-a[2][1];
                    }
                }
            }
        for(int i=0;i<3;i++)
        {
            int j=0;
            printf("%d",a[i][j]);
            for(int j=1;j<3;j++)
            {
                printf(" %d",a[i][j]);
            }
            printf("\n");
        }
    }
}
//没什么难度

