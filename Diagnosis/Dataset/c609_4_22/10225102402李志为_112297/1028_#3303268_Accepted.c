#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int k[1000];
    int t;
} N;
int cmp(const void*a,const void*b)
{
    int x=0;
    while(((N*)b)->k[x]==((N*)a)->k[x]) x++;
    return ((N*)b)->k[x]-((N*)a)->k[x];
}
N p[1001];
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d\n",&n);
        for(int j=0;j<n;j++){
            int x=0;
            while(scanf("%d",&p[j].k[x++])) if(p[j].k[x-1]==-1) break;
            p[j].t=x-1;//t表示数的个数
        }
        qsort(p,n,sizeof(p[0]),cmp);
        for(int j=0;j<n;j++){
            for(int y=0;y<p[j].t;y++) printf("%d ",p[j].k[y]);
            printf("\n");
        }
    }
	return 0;
}