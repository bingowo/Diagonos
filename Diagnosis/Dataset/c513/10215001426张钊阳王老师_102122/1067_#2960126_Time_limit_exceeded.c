#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int t(int n);
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int n;
        scanf("%d",&n);



        printf("case #%d:\n",z);

        printf("%lld",t(n));

        printf("\n");
    }
    return 0;
}


long long int t(int n)
{
    if(n==1) return 1;
    else if(n==2) return 1;
    else if(n==0) return 0;

    return t(n-1)+t(n-2)+t(n-3);
}
