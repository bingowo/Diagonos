#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isGoodNum(long long n){
    if(n%9==0){
        //printf("aaaa\n");
        return 0;
    }
    char s[110];memset(s,0,110*sizeof(char));
    sprintf(s,"%lld",n);
    int len = strlen(s);
    for(int i = 0;i<len;i++){
        if(s[i]=='9'){
            //printf("hhh\n");
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long n = 0;
    scanf("%lld",&n);
    long long res = n+1;
    while(!isGoodNum(res)){
        res++;
    }
    printf("%lld",res);
    return 0;
}
