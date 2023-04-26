#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d",&a);
    for(int j=0;j<a;j++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int num=0;
        int u[32];
        int p[32];
        int e=0,r=0;
        do
        {
            u[e]=x%2;
            x=x/2;
            e++;
        }while(x>0);
        do
        {
            p[r]=y%2;
            y=y/2;
            r++;
        }while(y>0);
        if(r>e)
         {
           for(int c=0;c<r;c++)
            {
                if(u[c]!=p[c])
                    num++;
            }
         }
         else
         {
         for(int c=0;c<e;c++)
            {
                if(u[c]!=p[c])
                    num++;
            }
         }
        printf("%d",num);
        printf("\n");
    }
    return 0;
}