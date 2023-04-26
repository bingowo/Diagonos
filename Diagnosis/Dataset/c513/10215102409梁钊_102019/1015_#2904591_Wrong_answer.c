#include<stdio.h>
#include<string.h>

int main()
{
    int Primenum[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int T ;
    scanf("%d",&T) ;
    getchar();
    for(int i=0;i!=T;i++){
        int num1[25] , num2[25] ;
        int digits1 = 0 , digits2 = 0 ;
        while(scanf("%d",&num1[digits1++]) != EOF && getchar() != ' ') ;
        while(scanf("%d",&num2[digits2++]) != EOF && getchar() != '\n') ;
        int result[25] ; int n = digits1 >= digits2 ? digits1 : digits2 ;
        int count = 0 ;
        for(int k=0;k!=n;k++){
            if(k>=digits1){
                if(num2[k] + count >= Primenum[k]){
                    result[k] = num2[k] + count - Primenum[k] ;
                    count = 1 ;
                }
                else{
                    result[k] = num2[k] + count ;
                    count = 0 ;
                }
            }
            else if(k>=digits2){
                if(num1[k] + count >= Primenum[k]){
                    result[k] = num1[k] + count - Primenum[k] ;
                    count = 1 ;
                }
                else{
                    result[k] = num1[k] + count ;
                    count = 0 ;
                }
            }
            else{
                if(num1[k] + num2[k] + count >= Primenum[k]){
                    result[k] = num1[k] + num2[k] - Primenum[k] ;
                    count = 1 ;
                }
                else{
                    result[k] = num1[k] + num2[k] + count ;
                    count = 0 ;
                }
            }
        }
        printf("case #%d:\n",i) ;
        for(int i=0;i!=n;i++){
            printf("%d",result[i]) ;
            if(i!=n-1) printf(",") ;
        }
        printf("\n") ;
    }
}