#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    int *a1 = (int*)a,*b1 = (int*)b;
    while(*a1 == *b1){
        a1++;
        b1++;
    }
    return *b1 - *a1;
}

int main()
{
    int T,n,a[1000][51];
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        for(int j = 0;j < n;j++){
            int k = 0;
            scanf("%d",&a[j][k]);
            while(a[j][k++] != -1){
                scanf("%d",&a[j][k]);
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int j = 0;j < n;j++){
            int k = 0;
            while(a[j][k] != -1){
                printf("%d ",a[j][k++]);
            }
            printf("\n");
        }
    }
    return 0;
}
