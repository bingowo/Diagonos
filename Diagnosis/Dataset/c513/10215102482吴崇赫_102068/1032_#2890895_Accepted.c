#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 1005
#define M 55

int intcmp(int* a,int* b)
{
    for(int i=0,j=0;i<M&&j<M;++i,++j){
        if(a[i]>b[i])return 1;
        if(a[i]<b[i])return -1;
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    return -intcmp((int*)a,(int*)b);
}

int main()
{
    int T;
    scanf("%d\n",&T);
    while(T--){
        int n;scanf("%d\n",&n);
        int a[N][M];
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j)a[i][j]=-1;
        }
        int pj=0;
        for(int i=0;i<n;++i){
            pj=0;
            while(1){
                scanf("%d",&a[i][pj]);
                if(a[i][pj]==-1)break;
                pj++;
            }
        }
        int pk=0;
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;++i){
            pk=0;
            while(1){

                if(a[i][pk]!=-1){
                    printf("%d ",a[i][pk]);
                }
                else{
                    printf("\n");break;
                }
                pk++;
            }
        }

    }
    return 0;
}
