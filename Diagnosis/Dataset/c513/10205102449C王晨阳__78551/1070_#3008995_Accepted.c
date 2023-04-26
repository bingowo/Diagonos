#include <stdio.h>

int main()
{
    int n;
    int n00[21];int n01[21];int n1[21];
    n00[1] = 1; n1[1] = 1;
    n01[1] = 0; n00[2] = 1; n01[2] = 1; n1[2] = 2;
    for(int i=3;i<21;i++)
    {
        n00[i] = n00[i-1] + n01[i-1];
        n01[i] = n1[i-1];
        n1[i] = n00[i-1] + n1[i-1];
    }
    while(1)
    {
        scanf("%d",&n);
        if(n == -1) break;
        else
            printf("%d\n",n00[n]+n01[n]+n1[n]);
    }
    return 0;
}
