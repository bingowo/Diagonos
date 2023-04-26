#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef long long int lli;

lli nums[1000000];

int cmp(const void *a,const void *b){
    lli pa=*(lli*)a,pb=*(lli*)b;
    return pa>pb?1:-1;
}

int main()
{
    lli n,m;scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&nums[i]);
    }
    qsort(nums,n,sizeof(lli),cmp);
    lli minD=0;
    for(int i=0;i<m-1;i++){
        minD+=nums[m-1]-nums[i];
    }
    lli tmp=minD;
    for(int i=1;i+m-1<n;i++){
        tmp=tmp-(m-1)*nums[i+m-2]+(m-1)*nums[i+m-1]+nums[i-1];
        if(tmp<minD) minD=tmp;
    }
    printf("%lld",minD);
}







