#include<stdio.h>
#include<string.h>

int isHWnum(char* s , int a)
{
    char* p = s ;
    char* q = s + a - 1 ;
    for(int i = 0; i != a / 2; i++){
        if(*(p++) != *(q--)) return 0 ;
    }
    return 1 ;
}

int main()
{
    int n ;
    scanf("%d",&n) ;
    char s[11] = {0} ; int tmp = n ; int i = 0 ;
    while(tmp){
        s[i++] = tmp % 10 ;
        tmp /= 10 ;
    }
    int digit = i ;
    int step = 0 ;
    while(!isHWnum(s,digit)){
        int ans = 0 ;
        int r = 1 ;
        for(int i = strlen(s) - 1; i != -1; i--){
            ans += s[i] * r ;
            r *= 10 ;
        }
        n += ans ;
        int tmp = n ; i = 0 ;
        while(tmp){
            s[i++] = tmp % 10 ;
            tmp /= 10 ;
        }
        digit = i ;
        step ++ ;
    }
    printf("%d %d",step,n) ;
}