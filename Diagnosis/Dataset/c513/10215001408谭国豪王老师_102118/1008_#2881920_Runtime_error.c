#include <stdio.h>
#include <stdlib.h>

int main()
{   int i,n,a[10][2];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",f(a[i][0],a[i][1]));
    }

    return 0;
}
int f(int x,int y)
{
    int z,z1,t=0;
    z=x^y;
    while(z)
    {
        z1=z%2;
        if(z1==1)
        {
            t++;
        }
        z=z/2;
    }
    return t;
}