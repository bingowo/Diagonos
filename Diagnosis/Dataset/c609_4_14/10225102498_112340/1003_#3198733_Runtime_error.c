#include <stdio.h>
#include <stdlib.h>
#define H 2333

int main()
{
    int T,i,n;
    int s[100000];
    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        scanf("%d",&n);
        int k = 0;
        int h = H;
        while(h<=n)
        {
            h = h*H;
            k++;
        }
        //printf("h=%d\n",h);
        h = h/H;
        int j = 0;
        for(j=0; j<=k; j++)
        {
            printf("%d ",n/h);
            n = n - n/h*h;
            h = h/H;
        }
    }

    return 0;
}
