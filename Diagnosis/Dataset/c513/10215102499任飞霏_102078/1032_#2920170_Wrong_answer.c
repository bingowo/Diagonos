#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int *x = *(int(*)[1000])a;
    int *y = *(int(*)[1000])b;
    int i = 0;
    while(x[i]==y[i])i++;
    return y[i]-x[i];
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int N;
        scanf("%d",&N);
        int a[1000][50];
        for(int j = 0;j < N;j++){
            int k = 0;
            while(1){
                scanf("%d",&a[j][k]);
                if(a[j][k]==-1)break;
                k++;
            }
        }
        qsort(a,N,sizeof(a[0]),cmp);
        for(int j = 0;j < N;j++){
            int k = 0;
            while(a[j][k]!=-1){
                printf("%d ",a[j][k]);
                k++;
            }
            printf("\n");
        }
    }
    return 0;
}
