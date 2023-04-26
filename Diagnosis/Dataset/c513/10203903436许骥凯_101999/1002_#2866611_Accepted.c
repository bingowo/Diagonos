#include<stdio.h>
#include<string.h>

long long int transform(char* s){
    int table[123];
    for (int i = 0; i != 123; i++)
        table[i] = -1;

    int joke = 0, count = 0, hi = strlen(s)-1;
    for (int i = 0; i <= hi; i++){
        if (table[s[i]] == -1){
            if (i == 0) table[s[i]] = 1;
            else table[s[i]] = joke++;
            if (joke == 1) joke++;
            count++; 
        }
    }

    if (count == 1) count++;

    long long int res = 0;
    for (int i = 0; i <= hi; i++)
        res = count * res + table[s[i]];

    return res;
}


int main(){
    int n;
    char s[61];
    scanf("%d", &n);
    for (int i = 0; i != n && scanf("%s", s); i++){
        long long int res = transform(s);
        printf("case #%d:\n%lld\n", i, res);
        continue;
    }
}