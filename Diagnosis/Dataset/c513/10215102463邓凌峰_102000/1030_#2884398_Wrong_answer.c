#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lli;

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int t;scanf("%d",&t);
        lli nums[t];
        for(int j=0;j<t;j++){scanf("%lld",&nums[j]);}
//        for(int j=0;j<t;j++)printf("%lld%c",nums[j],j==t-1?'\n':' ');
    }
    return 0;
}
