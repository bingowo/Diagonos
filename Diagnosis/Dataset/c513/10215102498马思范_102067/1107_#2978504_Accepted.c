#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x[3][3];
        int c[3][3];
        for(int k=0;k<3;k++)
        {
            for(int z=0;z<3;z++)
            {
                c[k][z]=1;
            }
        }
        for(int j=0;j<3;j++)
        {
            for(int p=0;p<3;p++)
            {
                scanf("%d",&x[j][p]);
            }
        }
        printf("case #%d:\n",i);
        int g=0,h=0;
        for(g=0;g<3;g++)
        {
            for(h=0;h<3;h++)
            {
                while(x[g][h]>0)
                {
                    if(g==0&&h==0)
                    {
                        c[g+1][h]=c[g+1][h]^1;
                        c[g][h]=c[g][h]^1;
                        c[g][h+1]=c[g][h+1]^1;
                        x[g][h]--;
                    }
                    if(g==0&&h==1)
                    {
                        c[g+1][h]=c[g+1][h]^1;
                        c[g][h]=c[g][h]^1;
                        c[g][h+1]=c[g][h+1]^1;
                        c[g][h-1]=c[g][h-1]^1;
                        x[g][h]--;
                    }
                    if(g==0&&h==2)
                    {
                        c[g][h-1]=c[g][h-1]^1;
                        c[g][h]=c[g][h]^1;
                        c[g+1][h]=c[g+1][h]^1;
                        x[g][h]--;
                    }
                    if(g==1&&h==0)
                    {
                        c[g+1][h]=c[g+1][h]^1;
                        c[g][h]=c[g][h]^1;
                        c[g][h+1]=c[g][h+1]^1;
                        c[g-1][h]=c[g-1][h]^1;
                        x[g][h]--;
                    }
                    if(g==1&&h==1)
                    {
                        c[g+1][h]=c[g+1][h]^1;
                        c[g][h]=c[g][h]^1;
                        c[g][h+1]=c[g][h+1]^1;
                        c[g][h-1]=c[g][h-1]^1;
                        c[g-1][h]=c[g-1][h]^1;
                        x[g][h]--;
                    }
                    if(g==1&&h==2)
                    {
                        c[g+1][h]=c[g+1][h]^1;
                        c[g][h]=c[g][h]^1;
                        c[g][h-1]=c[g][h-1]^1;
                        c[g-1][h]=c[g-1][h]^1;
                        x[g][h]--;
                    }
                    if(g==2&&h==0)
                    {
                        c[g][h+1]=c[g][h+1]^1;
                        c[g][h]=c[g][h]^1;
                        c[g-1][h]=c[g-1][h]^1;
                        x[g][h]--;
                    }
                    if(g==2&&h==1)
                    {
                        c[g][h]=c[g][h]^1;
                        c[g][h+1]=c[g][h+1]^1;
                        c[g][h-1]=c[g][h-1]^1;
                        c[g-1][h]=c[g-1][h]^1;
                        x[g][h]--;
                    }
                    if(g==2&&h==2)
                    {
                        c[g][h]=c[g][h]^1;
                        c[g][h-1]=c[g][h-1]^1;
                        c[g-1][h]=c[g-1][h]^1;
                        x[g][h]--;
                    }
                }
            }
        }
        for(int q=0;q<3;q++)
        {
            for(int w=0;w<3;w++)
            {
                printf("%d%c",c[q][w],w==2?'\n':' ');
            }
        }

    }
    return 0;
}