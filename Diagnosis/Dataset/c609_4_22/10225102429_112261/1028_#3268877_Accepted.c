#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
 typedef struct{
     int a[N];
     int len;
}node;
int cmp(const void* a, const void* b){
    int *pa = (*(node*)a).a,*pb = (*(node*)b).a;
    while(*pa==*pb){
        pa++,pb++;
    }
    return *pb-*pa;
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        node Lptr[n];
        for(int i = 0; i<n; i++){
            int *p = Lptr[i].a;
            memset(p,0,sizeof p);
            int k,j = 0;
            while(scanf("%d",&k)&&k!=-1) p[j++] = k;
            Lptr[i].len = j;
        }
        qsort(Lptr,n,sizeof(node),cmp);
        for(int i = 0; i<n; i++){
            int Len = Lptr[i].len;
            int *p = Lptr[i].a;
            for(int j = 0; j<Len; j++){
                printf("%d ",p[j]);
            }
            printf("\n");
        }
    }
    return 0;
}