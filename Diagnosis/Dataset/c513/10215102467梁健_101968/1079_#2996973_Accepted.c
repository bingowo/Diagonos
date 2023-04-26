#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
    int a1=*(int*)a,b1=*(int *)b;
    return a1>b1?1:-1;
}
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        int n,m;
        scanf("%d %d",&n,&m);
        int s[n+1];
        for(int i=0;i<n;i++){
            scanf("%d",&s[i]);
        }
        int size=n*(n+1)/2+1;
        int res[size];
        int k=0;
        for(int i=0;i<n;i++){
                res[k++]=s[i];
            for(int j=i+1;j<n;j++){
                res[k]=res[k-1]+s[j];
                k++;
            }
        }
        qsort(res,k,sizeof(int),cmp);
        long long R=0;
        int l,u;
        for(int i=0;i<m;i++){
            R=0;
            scanf("%d %d",&l,&u);
            for(int k=l-1;k<u;k++){
                R+=res[k];
            }
            printf("%lld\n",R);
        }
    }
    return 0;
}
