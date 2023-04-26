#include<stdio.h>

#define N 95

typedef struct{
    int cnt ;
    int c[N] ;
} bigint ;

int main()
{
    int t ;
    scanf("%d",&t) ;
    for(int i = 0; i != t; i++){
        int a , n ;
        scanf("%d %d",&a,&n) ;
        bigint result = {1,{1}} ;
        for (int j = 0; j < n; j++)
        {
            int carry = 0 ;
            for(int k = 0; k!=result.cnt; k++){
                int tmp = result.c[k] * a + carry ;
                if(tmp > 9){
                    carry = tmp / 10 ;
                    result.c[k] = tmp % 10 ;
                }
                else{
                    result.c[k] = tmp ;
                    carry = 0 ;
                }
            }
            if(carry) result.c[result.cnt++] = carry ; 
        }
        printf("case #%d:\n",i) ;
        for(int j = result.cnt - 1; j != -1; j--){
            printf("%d",result.c[j]) ;
        }
        printf("\n") ;
        
    }
}