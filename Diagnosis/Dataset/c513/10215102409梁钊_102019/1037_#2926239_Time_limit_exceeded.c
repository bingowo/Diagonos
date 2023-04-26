#include<stdio.h>
#include<stdlib.h>

int cmp(const void* _a , const void* _b)
{
    long long* a = (long long*)_a ; long long* b = (long long*)_b ;
    return *a - *b >= 0 ? 1 : -1 ;
}

int main()
{
    int n , m ;
    scanf("%d %d",&n,&m) ;
    long long nums[n] ;
    for(int i = 0 ; i != n ; i++){
        scanf("%lld",&nums[i]) ;
    }
    qsort(nums,n,sizeof(nums[0]),cmp) ;
    long long result = 0 ;
    long long least = 0 ;
    int idx = n-1 ;
    int flag = 1 ;
    for(int i = idx ; i >= m-1 ; i--){
        result = 0 ;
        long long tmp[m] ;
        for(int j = 0 ; j != m ; j++){
            tmp[j] = nums[i-j] ;
        }
        for(int j = 1 ; j != m ; j++){
            result += tmp[0] - tmp[j] ;
        }
        if(result<least || flag == 1){
            least = result ;
            flag = 0 ;
        } 

    }
    printf("%lld",least) ;
}