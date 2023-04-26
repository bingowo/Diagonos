#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void*b){
    return *(int*)a - *(int*)b;
}
int main()
{
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++)
    {
        int ps = 1;
        printf("case #%d\n",i);
        int n,m; scanf("%d%d",&n,&m);
        int a[n],s[n*(n+1)/2];
        for(int j = 0; j<n; j++){
            scanf("%d",&a[i]);
        }
        for(int j = 0; j<n; j++)
        {
            for(int k = j; k<n; k++)
            {
                int sum = 0;
                for(int t = j; t<=k; t++)
                    sum+=a[t];
                s[ps++] = sum;
            }
        }
        for(int j = 0; j<m; j++)
        {
            int l,u,sum = 0; scanf("%d%d"&l,&u);
            for(int t = l; t<=u; t++)
            {
                sum+=s[t];
            }
            printf("%d\n",sum);
        }
    }
    
}