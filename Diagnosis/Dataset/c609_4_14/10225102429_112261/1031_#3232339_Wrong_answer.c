#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a, const void*b){
    return *(long long*)a - *(long long*)b;
}
int main()
{
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++)
    {
        int ps = 1;
        printf("case #%d:\n",i);
        int n,m; scanf("%d%d",&n,&m);
        int N = n*(n+1)/2;
        int a[n];
        long long s[N+1];
        memset(s,0,sizeof s);
        for(int j = 0; j<n; j++){
            scanf("%d",&a[j]);
        }
//        for(int j = 0; j<n; j++){
//        	printf("a[%d] = %d ",j,a[j]);
//		}
        for(int j = 0; j<n; j++)
        {
            for(int k = j; k<n; k++)
            {
                long long sum = 0;
                for(int t = j; t<=k; t++)
                    sum+=a[t];
                s[ps++] = sum;
//                printf("sum = %d ",sum);
            }
        }
        qsort(s,N+1,sizeof(long long),cmp); 
        for(int j = 0; j<m; j++)
        {
            int l,u,sum = 0; scanf("%d%d",&l,&u);
            for(int t = l; t<=u; t++)
            {
                sum+=s[t];
            }
            printf("%lld\n",sum);
        }
//        for(int j = 1; j<=N; j++)
//        	printf("%d ",s[j]);
    }
    
}