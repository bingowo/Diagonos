#include<stdio.h>
#include<stdlib.h>

int cmp(const void *_a , const void *_b)
{
    int* a = (int *)_a ; int* b = (int *)_b ;
    while(*a != -1 && *b != -1){
        if(*a != *b) return *b > *a ;
        else{
            a++ ;
            b++ ;
        }
        if(*a == -1) return 1 ;
        else if(*b == -1) return -1 ;
    }
}

int main()
{
    int t = 0 , n = 0 ;
    scanf("%d",&t) ;
    for(int i=0; i<t; i++){
        scanf("%d",&n) ;
        int p[n][50];
        int idx = 0 ;
        for(int j=0;j<n;j++){
            while(scanf("%d",&p[j][idx]) && getchar()!='\n') idx++ ;
            idx = 0 ;
        }
        qsort(p,n,sizeof(p[0]),cmp) ;
        for(int j=0; j<n; j++){
            while(p[j][idx]!=-1)
                printf("%d ",p[j][idx++]) ;
            idx = 0 ;
            printf("\n") ;
        }
    }
}