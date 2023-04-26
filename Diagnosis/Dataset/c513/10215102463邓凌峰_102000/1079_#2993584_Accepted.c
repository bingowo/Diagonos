#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 500500
#define BigNUm 10007

typedef long long lli;

int cmp(const void *a,const void *b){
    lli pa=*(lli*)a,pb=*(lli*)b;
    return pa>pb?1:-1;
}

int main()
{
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        int n,m;scanf("%d%d",&n,&m);
        lli nums[n];
        for(int i=0;i<n;i++) scanf("%lld",&nums[i]);

        lli N[LEN]={0};
        lli cnt=0,max=n*(n+1)/2;
        for(int smallLen=1;smallLen<=n;smallLen++){
            for(int start=0;start+smallLen<=n;start++){
                   for(int idx=0;idx<smallLen;idx++){
                        N[cnt]+=nums[start+idx];
                   }
                   cnt++;
            }
        }

        qsort(N,max,sizeof(lli),cmp);




        printf("case #%d:\n",I);
        int L,U;
        for(int j=0;j<m;j++){
            scanf("%d%d",&L,&U);
            lli ans=0;
            for(int k=L-1;k<=U-1;k++){
                ans+=N[k];
            }
            printf("%lld\n",ans);

        }

    }

    return 0;
}
