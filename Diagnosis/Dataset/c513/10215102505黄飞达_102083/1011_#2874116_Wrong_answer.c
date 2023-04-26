#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long


int main(){
    ll num = 0;
    scanf("%llX", &num); 
    char bin[200] = {0};
    for (int i = 0; i < 64; i++){
        bin[i] = ((num>>(63-i)) & 1) + '0';
    }
    //puts(bin);
    ll a, b, c = 0, d = 0;
    for (int i = 0; bin[i]; i++){
        ll r = bin[i] - '0';
        a = -c - d + r;
        b = c - d;
        c = a;
        d = b;
    }
    if (a != 0){
        printf("%lld", a);
        if (b > 0){
            if (b == 1) printf("+i");
            else printf("+%lldi", b);
        } 
        else if (b < 0){
            if (b == -1) printf("-i");
            else printf("%lldi", b);
        } 
    } 
    else{
        if (b > 0){
            if (b == 1) printf("i");
            else printf("%lldi", b);
        } 
        else if (b < 0){
            if (b == -1) printf("-i");
            else printf("%lldi", b);
        } 
        else printf("0");
    }
    printf("\n");
    return 0;
}