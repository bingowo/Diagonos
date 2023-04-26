#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lli;


int cmp(const void *a,const void *b)
{
    lli pa=*(lli*)a,pb=*(lli*)b;
    return pa>pb?1:-1;
}

int main()
{
    int n;scanf("%d",&n);
    lli nums[n];
    for(int i=0;i<n;i++){scanf("%lld",&nums[i]);}
    qsort(nums,n,sizeof(lli),cmp);
    lli sum=0;
    for(int j=0;j<n;j+=2){
        sum+=nums[j+1]-nums[j];
    }
    printf("%lld",sum);
	return 0;
}
