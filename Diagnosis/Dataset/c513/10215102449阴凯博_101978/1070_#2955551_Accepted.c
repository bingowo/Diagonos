#include <stdio.h>
#include <stdlib.h>


int arr[22]={0,2,4,7};


int main()
{
    int n=1;
    while (1)
    {
        scanf("%d",&n);
        if (n==-1) break;
        else
        {
            int m=1;
            for (int i=4;i<21;i++)
                arr[i]=2*arr[i-1]-arr[i-2]+arr[i-3];
            printf("%d\n",arr[n]);
        }
    }
    return 0;
}
