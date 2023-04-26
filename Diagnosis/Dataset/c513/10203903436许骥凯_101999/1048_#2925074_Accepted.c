#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long int

void calco(char *s, ll *co){
    while(*s){
        ll sig = 1, coef = 0, power = 0;
        if (*s == '-'){s++, sig = -1;}
        else if(*s == '+') s++;
        while(*s >= '0' && *s <= '9'){
            coef = (*s) - '0' + coef * 10;
            s++;
        }
        if (*s == '\0'){co[0] = coef * sig; return;}
        else if (*s == 'x'){
            if (!coef) coef = 1;
            s++;
            if (*s == '^'){
                s++;
                while(*s >= '0' && *s <= '9'){
                    power = (*s) - '0' + power * 10;
                    s++;
                }
            }
            else power = 1;
            co[power] = coef * sig;
        }
    }
}

void mul(char *c1, char *c2, ll *arr){
    ll co1[501];
    ll co2[501];
    memset(co1, 0, sizeof(ll) * 501);
    memset(co2, 0, sizeof(ll) * 501);
    calco(c1, co1);
    calco(c2, co2);
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            arr[i+j] += co1[i] * co2[j];
}

int main(){
    char s1[101], s2[101];
    while(scanf("%s%s", s1, s2) == 2){
        ll coef[1000];
        ll out[1000];
        memset(coef, 0, sizeof(ll) * 1000);
        mul(s1, s2, coef);
        int sig = 0;
        for (int i = 0; i < 1000; i++)
            if (coef[i]) out[sig++] = coef[i];
        for (int i = sig - 1; i >= 0; i--)
            printf("%d%c", out[i], i == 0? '\n': ' ');
    }
    return 0;
}