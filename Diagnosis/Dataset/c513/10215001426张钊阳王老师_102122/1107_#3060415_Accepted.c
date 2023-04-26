#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        int light[3][3];
        for(int t=0;t<3;t++)
        {
            for(int j=0;j<3;j++)
            {
                light[t][j]=0;
            }
        }
        int temp[3][3];
        for(int k=0;k<3;k++)
        {
            for(int j=0;j<3;j++)
            {
                scanf("%d",&temp[k][j]);
                int time=temp[k][j];
                for(int p=0;p<time;p++)
                {
                    light[k][j]++;
                if(k-1>=0)
                {
                    light[k-1][j]++;
                }
                if(k+1<=2)
                {
                    light[k+1][j]++;
                }
                if(j-1>=0)
                {
                    light[k][j-1]++;
                }
                if(j+1<=2)
                {
                    light[k][j+1]++;
                }
                }
            }
        }
        /*for(int t=0;t<3;t++)
        {
            for(int j=0;j<3;j++)
            {
                printf("%d",light[t][j]);
            }
        }*/

        printf("case #%d:\n",z);

        for(int g=0;g<3;g++)
            for(int h=0;h<3;h++)
        {
            if(light[g][h]%2==0) printf("1");
            else printf("0");
            if(h!=2) printf(" ");
            else if(h==2) printf("\n");
        }
    }
    return 0;
}
