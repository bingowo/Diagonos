#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int n;
        scanf("%d",&n);
        int w,x,y,z;
        int t=0;
        if(n==0)
        {
            printf("1\n");
        }
        else
        {
            for(int z=0;z<=n;z++)
            {
                for(int x=0;x<=(n-z)/2;x++)
                {
                    for(int y=0;y<=(n-z-2*x)/3;y++)
                    {
                        if((n-z-2*x-3*y)%4==0)
                        {
                            t++;
                        }
                    }
                }
            }
            printf("%d\n",t);
        }
    }
    return 0;
}