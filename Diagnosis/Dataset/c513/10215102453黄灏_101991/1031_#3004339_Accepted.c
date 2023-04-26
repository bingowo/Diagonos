#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp1(const void *a,const void *b){
    int x=*(int*)a;
    int y=*(int*)b;
    return x-y;
}

int cmp2(const void *a,const void *b){
    int x=*(int*)a;
    int y=*(int*)b;
    return y-x;
}

int main() {
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        int n=0;
        scanf("%d\n",&n);
        int a[1000],b[1000];
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);getchar();
        }
        for(int j=0;j<n;j++){
            scanf("%d",&b[j]);getchar();
        }
        qsort(a,n,sizeof(a[0]),cmp1);
        qsort(b,n,sizeof(b[0]),cmp2);
        int sum=0;
        for(int j=0;j<n;j++){
            sum += a[j]*b[j];
        }
        printf("case #%d:\n",i);
        printf("%d\n",sum);
        
    }
    return 0;
}
