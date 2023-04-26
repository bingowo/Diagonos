#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        long x,y,z;
        int n=0;
        scanf("%ld %ld",&x,&y);
        z=x^y;
        while(z!=0)
        {
            n=n+z%2;
            z=z/2;
        }
        printf("%d\n",n);
    }
    return 0;
}
