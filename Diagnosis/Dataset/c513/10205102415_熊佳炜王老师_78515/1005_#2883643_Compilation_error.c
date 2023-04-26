#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(char s[]){
    float ans = 0;
    for(int p = 0;p < strlen(s); p++){
        ans += pow(0.125,s[p+2]);
    }
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        char[s] = "\0";
        gets(s);
        printf("case #%d:\n", i);
        printf("%f", f(s));
    }
    return 0;
}