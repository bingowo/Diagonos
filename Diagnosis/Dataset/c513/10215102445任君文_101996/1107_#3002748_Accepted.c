#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T;
    int i,j,k;
    int m=0;
    int light[3][3]={1};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        for(j=0;j<3;j++)
        {
            light[j][0]=1;
            light[j][1]=1;
            light[j][2]=1;
        }
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                scanf("%d",&m);
                if(m%2==1)
                {
                    if(j==0)
                    {
                        if(k==0)
                        {
                            light[j][k]=1-light[j][k];
                            light[j][k+1]=1-light[j][k+1];
                            light[j+1][k]=1-light[j+1][k];
                        }
                        else if(k==1)
                        {
                            light[j][k]=1-light[j][k];
                            light[j][k-1]=1-light[j][k-1];
                            light[j][k+1]=1-light[j][k+1];
                            light[j+1][k]=1-light[j+1][k];
                        }
                        else
                        {
                            light[j][k]=1-light[j][k];
                            light[j+1][k]=1-light[j+1][k];
                            light[j][k-1]=1-light[j][k-1];
                        }
                    }
                    else if(j==1)
                    {
                        if(k==0)
                        {
                            light[j][k]=1-light[j][k];
                            light[j][k+1]=1-light[j][k+1];
                            light[j+1][k]=1-light[j+1][k];
                            light[j-1][k]=1-light[j-1][k];
                        }
                        else if(k==1)
                        {
                            light[j][k]=1-light[j][k];
                            light[j][k-1]=1-light[j][k-1];
                            light[j][k+1]=1-light[j][k+1];
                            light[j+1][k]=1-light[j+1][k];
                            light[j-1][k]=1-light[j-1][k];
                        }
                        else
                        {
                            light[j][k]=1-light[j][k];
                            light[j+1][k]=1-light[j+1][k];
                            light[j][k-1]=1-light[j][k-1];
                            light[j-1][k]=1-light[j-1][k];
                        }
                    }
                    else
                    {
                        if(k==0)
                        {
                            light[j][k]=1-light[j][k];
                            light[j][k+1]=1-light[j][k+1];
                            light[j-1][k]=1-light[j-1][k];
                        }
                        else if(k==1)
                        {
                            light[j][k]=1-light[j][k];
                            light[j][k-1]=1-light[j][k-1];
                            light[j][k+1]=1-light[j][k+1];
                            light[j-1][k]=1-light[j-1][k];
                        }
                        else
                        {
                            light[j][k]=1-light[j][k];
                            light[j-1][k]=1-light[j-1][k];
                            light[j][k-1]=1-light[j][k-1];
                        }
                    }
                }
                
            }
        }
        printf("case #%d:\n",i);
        for(j=0;j<3;j++)
        {
            printf("%d %d %d\n",light[j][0],light[j][1],light[j][2]);
        }
    }
    return 0;
}