#include<stdio.h>
#include<stdlib.h>

int acmp(const void* _a , const void* _b)
{
    int* a = (int*) _a ; int* b = (int*)_b ;
    return *a - *b > 0 ? 1 : -1 ;
}

int dcmp(const void* _a , const void* _b)
{
    int* a = (int*) _a ; int* b = (int*)_b ;
    return *b - *a > 0 ? 1 : -1 ;
}

int main()
{
    int t ;
    scanf("%d",&t) ;
    for (int i = 0 ; i != t ; i++)
    {
        int n ;
        scanf("%d",&n) ;
        int n1[n] , n2[n] ;
        for(int j = 0 ; j != n ; j++) {
            scanf("%d",&n1[j]) ;
        }
        for(int j = 0 ; j != n ; j++ ){
            scanf("%d",&n2[j]) ;
        }
        qsort(n1,n,sizeof(int),acmp) ;
        qsort(n2,n,sizeof(int),dcmp) ;
        int result = 0 ;
        for(int j = 0 ; j != n ; j++){
            result += n1[j] * n2[j] ;
        }
        printf("case #%d:\n%d",i,result) ;

    }
    
}