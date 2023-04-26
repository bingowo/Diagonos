#include<stdio.h>


int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        unsigned long long int ans=1;
        for(int j=0;j<n;j++)
        {
            ans = ans*2;
        }
        printf("%llu\n",ans);
        
    }
    return 0;
    
}
