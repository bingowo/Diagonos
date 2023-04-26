#include<stdio.h>
#include<string.h>
int main(){
    int table[123];
    for (int i = 'A'; i != 'Z' + 1; i++)
        table[i] = 10 + i - 'A';
    for (int i = '0'; i != '9' + 1; i++)
        table[i] = i - '0';
    
    char hex[50];
    int bin[1000];

    scanf("%s", hex);
    int len = strlen(hex);

    for (int i = 2; i != len; i++){
        int temp = table[hex[i]];
        for (int j = 0; j != 4; j++){
            bin[4*(i-2)+j] = temp % 2;
            temp /= 2;
        } 
    }
    long long int a = 0, b = 0;
    for (int i = 0; i != len - 2; i++){
        for (int j = i * 4 + 3; j >= i * 4; j--){
            int mod = bin[j];
            long long int temp = a;
            a = - (b + a) + mod;
            b = temp - b;
        }
    }

    if (a == 0){
        if (b == 0) printf("0\n");
        else if (b == 1) printf("i\n");
        else if (b == -1) printf("-i\n");
        else printf("%lldi\n", b);
    }
    else if (b == 0) printf("%lld\n", a);
    else if (b == 1) printf("%lld+i\n", a);
    else if (b == -1) printf("%lld-i\n", a);
    else printf("%lld%+.lldi\n", a, b); 
    return 0;
}