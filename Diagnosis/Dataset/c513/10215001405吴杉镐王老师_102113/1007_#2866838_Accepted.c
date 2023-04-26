#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int x;
    scanf("%d",&x);
    int y=0;
    while(y<x)
    {
        printf("case #%d:\n",y);
        y++;
        int count=1;
        int m;
        scanf("%d",&m);
        int a,b;
        a=m%2;
        m=m/2;
        int max=1;
        while(m!=0)
        {
            b=m%2;
            if(a!=b)
            {
                count++;
                //printf("!");
            }
            else
            {
                //printf("!");
                if(count>max) max=count;
                count=1;
            }
            m=m/2;
            a=b;
        }
        if(count>max) max=count;
        printf("%d\n",max);
    }
}
