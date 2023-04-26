#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double cal(){
    char s[101];
    scanf("%s", s);
    double res = 0;
    switch(s[0]){ 
        case '+': res = cal() + cal(); break;
        case '-': res = cal() - cal(); break;
        case '*': res = cal() * cal(); break;
        case '/': res = cal() / cal(); break;
        default: res = atof(s); break;
    }
    return res;
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        printf("case #%d:\n", i);
        printf("%.6f\n", cal());
    }
    return 0;
}