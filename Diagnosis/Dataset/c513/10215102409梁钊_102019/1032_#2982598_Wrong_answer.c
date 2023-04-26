#include<stdio.h>
#include<stdlib.h>

int highest(int x)
{
    int res = 0 ;
    if(x < 0) x *= -1 ;
    while(x){
        res = x % 10 ;
        x /= 10 ;
    }
    return res ;
}

int cmp(const void *_a , const void *_b)
{
    int* a = (int *)_a ; int* b = (int *)_b ;
    do{
        int a_ = highest(*a) , b_ = highest(*b) ;
        if(a_ != b_) return b_ > a_ ;
        else{
            a++ ;
            b++ ;
        }
    }while(*a!=-1) ;
    return -1 ;
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