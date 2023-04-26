#include<stdio.h>
#include<string.h>
int main()
{
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        int a,b,c;
        int d[2000];
        scanf("%d%d",&a,&b);
        d[0]=1;
        for(int k=0;k<b;k++)
        {
            int m=strlen(d);
            for(int j=0;j<m;j++)
            {
                d[j]=d[j]*a;
                if(d[j]>9)
                {
                    d[j+1]=d[j]/10;
                }

            }
        }
        int y=strlen(d);
        for(int k=y-1;k>=0;k--)
        {
            printf("%d",d[k]);
        }
        printf("\n");


    }
}