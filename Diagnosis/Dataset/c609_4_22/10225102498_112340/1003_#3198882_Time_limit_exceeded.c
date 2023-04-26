#include <stdio.h>
#include <stdlib.h>
#define H 2333

int main()
{
    long long T,i,n;
    scanf("%d",&T);
    for(i=0; i<T; i++)
    {
        scanf("%d",&n);
        int k = 0;
        long long h = H;
        while(h<=n)
        {
            h = h*H;
            k++;
        }
        //printf("h=%d\nk=%d",h,k);
        h = h/H;
        int j = 0;
        for(j=0; j<=k; j++)
        {
            printf("%d ",n/h);
            n = n - n/h*h;
            h = h/H;
        }
        printf("\n");
    }

    return 0;
}
