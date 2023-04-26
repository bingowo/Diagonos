#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int col[100] ;
}row;

int cmp(const void *_a , const void *_b)
{
    int i = 0 ;
    row* a = (row *)_a ; row* b = (row *)_b ;
    while((*a).col[i] != -1 && (*b).col[i] != -1){
        if((*a).col[i] != (*b).col[i]) return (*b).col[i] > (*a).col[i] ;
        else i++ ;
    }
    if((*a).col[i] == -1) return 1 ;
    else return -1 ;
}

int main()
{
    int t = 0 , n = 0 ;
    scanf("%d",&t) ;
    for(int i=0; i<t; i++){
        scanf("%d",&n) ;
        row row[n] ;
        int idx = 0 ;
        for(int j=0;j<n;j++){
            while(scanf("%d",&row[j].col[idx]) && getchar()!='\n') idx++ ;
            idx = 0 ;
        }
        qsort(row,n,sizeof(row[0]),cmp) ;
        for(int j=0; j<n; j++){
            while(row[j].col[idx]!=-1)
                printf("%d ",row[j].col[idx++]) ;
            idx = 0 ;
            printf("\n") ;
        }
    }
}