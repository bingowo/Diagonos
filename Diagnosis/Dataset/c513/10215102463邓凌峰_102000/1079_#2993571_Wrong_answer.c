#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 500500
#define BigNUm 10007

int cmp(const void *a,const void *b){
    int pa=*(int*)a,pb=*(int*)b;
    return pa>pb?1:-1;
}

int main()
{
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        int n,m;scanf("%d%d",&n,&m);
        int nums[n];
        for(int i=0;i<n;i++) scanf("%d",&nums[i]);

        int N[LEN]={0};
        int cnt=0,max=n*(n+1)/2;
        for(int smallLen=1;smallLen<=n;smallLen++){
            for(int start=0;start+smallLen<=n;start++){
                   for(int idx=0;idx<smallLen;idx++){
                        N[cnt]+=nums[start+idx];
                   }
                   cnt++;
            }
        }

        qsort(N,max,sizeof(int),cmp);




        printf("case #%d:\n",I);
        int L,U;
        for(int j=0;j<m;j++){
            scanf("%d%d",&L,&U);
            int ans=0;
            for(int k=L-1;k<=U-1;k++){
                ans+=N[k];
            }
            printf("%d\n",ans);

        }

    }

    return 0;
}
