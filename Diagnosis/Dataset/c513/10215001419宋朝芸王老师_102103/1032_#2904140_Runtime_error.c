#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    int *pa= *(int**)a, *pb=*(int**)b;

    while(*pa != -1 && *pb != -1){
        if(*pa != *pb) return (*pb - *pa);
        pa++,pb++;
    }
    if(*pa == *pb) return 0;
    if(*pa == -1) return 1;
    if(*pb == -1) return -1;
}


int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int n;
        scanf("%d",&n);

        int **a = (int**)malloc(n*sizeof(int*));
        for(int i = 0; i < n; i++){
            int j = 0,temp;
            while(scanf("%d",&temp) && temp != -1){
                a[i][j++] = temp;
            }
            a[i][j] = -1;
        }

        qsort(a,n,sizeof(int*),cmp);

        for(int i = 0; i < n; i++){
            printf("%d",a[i][0]);
            for(int j = 1; a[i][j] != -1; j++){
                printf(" %d",a[i][j]);
            }
            printf("\n");
        }

        free(a);
    }
    return 0;
}
