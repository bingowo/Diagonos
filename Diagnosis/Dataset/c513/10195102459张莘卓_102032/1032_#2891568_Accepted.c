#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* m, const void* n){
    int *a=*((int**)m), *b=*((int**)n);
    int i = 0;
    while(a[i] == b[i]) ++i;
    return b[i] - a[i];
}
 
int main()
{
    int T; scanf("%d",&T);
    for(int j=0; j<T; ++j ) {
        int N;  scanf("%d",&N);
        int **a = (int**)malloc(N*sizeof(int*));
        for(int i=0; i<N; ++i) {
            int k = 0;
            a[i] = (int*)malloc(51*sizeof(int));
            do{
                scanf("%d",&a[i][k]);
            }while(a[i][k++] != -1);
        }
        qsort(a, N, sizeof(int*), cmp);
        for(int i=0; i<N; ++i) {
            int k = 0;
            while(a[i][k] != -1){
                if(k) printf(" ");
                printf("%d",a[i][k++]);
            }
            free(a[i]);
            printf("\n");
        }
        free(a);
    }
    return 0;
}
