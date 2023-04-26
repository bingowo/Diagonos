#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int gcd(long long int up, long long int down){
    long long int temp;
    while(down % up != 0){
        temp = down % up;
        down = up;
        up = temp;
    }
    return up;
}

int main()
{
    char s[100];
    scanf("%s",s);
    int p;
    long long int left = 0, up = 0, down = 1;
    for(p = 0; p < strlen(s); p++){
        if (s[p] == '.'){
            break;
        }
        left = left * 3;
        if (s[p] == '1'){
            left = left + 1;
        }else if (s[p] == '2'){
            left = left - 1;
        }
    }
    p++;
    for(; p < strlen(s); p++){
        down = down * 3;
        up = up * 3;
        if (s[p] == '1'){
            up = up + 1;
        }else if (s[p] == '2'){
            up = up - 1;
        }
    }
    if ((left != 0) && (up < 0)){
        left = left - 1;
        up = up + down;
    }else if((left <0) && (up > 0)){
        left = left + 1;
        up = down - up;
        if (left == 0){
            up = - up;
        }
    }
    if (up == 0){
        printf("%lld\n",left);
    }else{
        long long int t = gcd( abs(up), abs(down));
        if (left != 0){
            printf("%lld ",left);
        }
        printf("%lld %lld\n",up / t, down / t);
    }
    return 0;
}
