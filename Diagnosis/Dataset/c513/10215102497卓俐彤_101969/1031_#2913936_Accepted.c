#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compar(const void*a,const void*b){
    int d1,d2;
    d1=*((int*)a);
    d2=*((int*)b);
    return d1-d2;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int N;
        scanf("%d",&N);
        int a[N],b[N];
        for(int n=0;n<N;n++){
            scanf("%d",&a[n]);
        }
        for(int n=0;n<N;n++){
            scanf("%d",&b[n]);
        }
        int i=0,j=N-1;
        int minnum=0;
        qsort(a, N, sizeof(a[0]), compar);
        qsort(b, N, sizeof(b[0]), compar);
        for(;i<N;i++)minnum+=a[i]*b[j--];
        printf("%d\n",minnum);
    }
    return 0;
}
