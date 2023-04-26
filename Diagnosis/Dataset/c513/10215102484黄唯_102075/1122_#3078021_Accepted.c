#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T); 
    for(int i=0;i<T;i++) 
    { long long n;scanf("%lld",&n);
    int ans[10],k=0; 
    do{ ans[k++]=n%2333; n=n/2333; }
    while(n); 
    for(int i=k-1;i>=0;i--) 
    printf("%d%c",ans[i],i==0?'\n':' ');
    }
    return 0; 
    
}