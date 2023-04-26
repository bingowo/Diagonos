#include<stdio.h>
#include<string.h>

int isHWnum(char* s)
{
    char* p = s ;
    char* q = s + strlen(s) - 1 ;
    for(int i = 0; i != strlen(s) / 2; i++){
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
    int step = 0 ;
    while(!isHWnum(s)){
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
        step ++ ;
    }
    printf("%d %d",step,n) ;
}