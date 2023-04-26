#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0; i<T; i++)
    {
        unsigned long long ans = 1;
        int n;
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
        	ans *= 2;
		}
		printf("case #%d:\n%lld",i,ans);
    }
    return 0;
}