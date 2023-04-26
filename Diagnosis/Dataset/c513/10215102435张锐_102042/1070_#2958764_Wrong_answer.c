#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        int sum=1;
        for(int i=0;i<n;i++)
        {
            sum+=(n-i);
        }
        printf("%d\n",sum);
        scanf("%d",&n);
    }
    return 0;
}