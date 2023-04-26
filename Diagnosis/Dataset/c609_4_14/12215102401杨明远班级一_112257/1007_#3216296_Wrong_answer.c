#include <stdio.h>
#include <stdlib.h>

#define N 10000

int comp(const void*a,const void *b){
    return (*(int*)a)-(*(int*)b);
}
int main(void)
{
    int n,j;
    scanf("%d",&n);

    for(int j = 0;j<n;j++){

        int T[N];
        int i,m;

        scanf("%d",&m);

        for(i=0;i<m;i++){
            scanf("%d",&T[i]);
        }

        int sz = sizeof(T)/sizeof(T[0]);

        qsort(T,sz,sizeof(int),comp);

        for(i=0;i<m-1;i++){

             printf("case #%d %d ",i,T[i]);

            }
        }

    return 0;
}