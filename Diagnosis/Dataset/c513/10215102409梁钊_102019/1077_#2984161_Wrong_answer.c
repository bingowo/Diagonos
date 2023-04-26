#include<stdio.h>
#include<stdlib.h>

int *A ;
int m , n ;

int get_p(int x)
{
    for(int i=0; i<m; i++){
        if(A[i] == x)
            return i ;
    }
    return 0 ;
}

int cmp1(const void *_a , const void *_b)
{
    int *a = (int*)_a , *b = (int*)_b ;
    int a_p = get_p(*a) , b_p = get_p(*b) ;
    return a_p > b_p ;

}

int cmp2(const void *_a , const void *_b)
{
    int *a = (int*)_a , *b = (int*)_b ;
    return *a > *b ;
}



int main()
{
    scanf("%d",&m) ;
    A = (int*)malloc(m*sizeof(int)) ;
    for(int i=0; i<m; i++){
        scanf("%d",&A[i]) ;
    }
    scanf("%d",&n) ;
    int B[n] ;
    for(int i=0; i<n; i++){
        scanf("%d",&B[i]) ;
    }
    int idx = 0 , count = 0 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[j] == B[i]){
                char tmp = B[idx] ;
                B[idx++] = A[j] ;
                B[i] = tmp ;
                count ++ ;
            }
        }
    }
    int B1[count] ; int B2[n-count] ;
    int j = 0 , k = 0 ;
    for(int i=0; i<n; i++){
        if(i < count)
            B1[j++] = B[i] ;
        else 
            B2[k++] = B[i] ;
    }
    qsort(B1,count,sizeof(B[0]),cmp1) ;
    qsort(B2,n - count,sizeof(B[0]),cmp2) ;
    for(int i=0; i<n; i++){
        if(i < count)
            printf("%d ",B1[i]) ;
        else
            if(i==n-1)
                printf("%d",B2[i-count]) ;
            else
                printf("%d ",B2[i-count]) ;
    }
    free (A) ;
}