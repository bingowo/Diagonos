#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int n;
        scanf("%d",&n);
        int sum;
        if(n==0) sum=1;
        else sum=(int)pow(2,n);

        printf("case #%d:\n",z);

        printf("%d",sum);

        printf("\n");

    }
    return 0;
}
