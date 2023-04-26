#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lli;

lli hi(lli x)
{
    lli mid=llabs(x);
    lli ans=mid;
    while(mid>0){
        if(mid<10){return ans;}
        mid/=10;
        ans=mid;
    }
}

void cmp(const void *a,const void *b)
{
    lli *pa=*(lli*)a,*pb=*(lli*)b;
    lli hia=hi(pa),hib=hi(pb);
    if(hia!=hib){return (hia>hib)?-1:1;}
    else {return (pa>pb)?1:-1;}

}



int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        int t;scanf("%d",&t);
        lli nums[t];
        for(int j=0;j<t;j++){scanf("%lld",&nums[j]);}
//        for(int j=0;j<t;j++)printf("%lld%c",nums[j],j==t-1?'\n':' ');
        qsort(nums,t,sizeof(nums[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<t;k++){
            printf("%lld%c",nums[k],k==t-1?'\n':' ');
        }
    }
    return 0;
}

