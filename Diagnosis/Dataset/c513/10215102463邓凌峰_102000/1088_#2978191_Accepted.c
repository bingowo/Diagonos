#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        long long m,n;scanf("%lld%lld",&m,&n);
        long long ans=1;
        for(long long i=0;i<n;i++){
            ans=ans*(m-i)/(i+1);
        }
        printf("case #%d:\n%lld\n",i,ans);

    }




    return 0;
}
