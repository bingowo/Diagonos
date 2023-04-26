//去重排序并统计去重后个数
#include<stdio.h>
void quicksort (int s[] , int l , int r) ;
int main () {
    int N ;
    scanf("%d" , &N) ;
    int s[N] ;
    int count = N , i;
    for (i = 0 ; i < N ; i++){
        scanf("%d" , &s[i]) ;
    }
    quicksort(s , 0 , N-1) ;
    for (i=1 ; i < count ; i++ ){
        if (s[i] == s[i-1]){
            count-- ;
            for (int j = i ;j <= count ; j++ ){
                s[j] = s[j+1] ;
            }
            i-- ;
        }
    }
    printf("%d\n" , count) ;
    for (i = 0 ; i < count -1 ; i++){
        printf("%d " , s[i]) ;
    }
    printf("%d" , s[i]) ;
    return 0 ;
}

void quicksort (int s[] , int l , int r){
    if (l >= r)
        return ;
    int i = l ;
    int j = r ;
    int x = s[i] ;
    while(i < j){
        while (s[j] > x && i < j)
            j-- ;
        if (i < j)
            s[i++] = s[j] ;
        while (s[i] < x && i < j)
            i++ ;
        if (i < j)
            s[j--] = s[i] ;
    }
    s[i] = x ;
    quicksort(s , l ,i-1) ;
    quicksort(s, i+1 , r) ;
}