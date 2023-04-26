#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *p1,const void *p2);

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        int N;
        scanf("%d",&N);
        int data[N][51];
        int temp;
        for(int v = 0; v < N; v++){
            int z = 0;
            for(scanf("%d",&temp);temp != -1;scanf("%d",&temp)){
                data[v][z] = temp;
                z++;
            }
            data[v][z] = -1;
        }
        
        qsort(data,N,sizeof(int[50]),cmp);
        
        for(int v = 0; v < N; v++){
            for(int z = 0; data[v][z] != -1; z++){
                printf("%d ",data[v][z]);
            }
            putchar('\n');
        }
    }

    return 0;
}

int cmp(const void *p1,const void *p2)
{
    int *a = (int*)p1;
    int *b = (int*)p2;
    while(*a == *b){
        a++;
        b++;
    }
    return *b > *a?1:*b < *a?-1:0;
}