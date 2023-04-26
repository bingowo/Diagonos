#include<stdio.h>
#include<ctype.h>

long long int transform(char* s, int hi){
    int table[123];
    for (int i = 0; i != 123; i++)
        table[i] = -1;

    int joke = 0, count = 0;
    for (int i = 0; i <= hi; i++)
        if (table[s[i]] == -1){
            if (i == 0) table[s[i]] = 1;
            else table[s[i]] = joke++;
            if (joke == 1) joke++;
            count++; 
        }
    if (count == 1) count++;
    long long int res = 0;
    for (int i = 0; i <= hi; i++)
        res = count * res + table[s[i]];
    return res;
}
int main(){
    int n;
    char s[61], c;
    scanf("%d", &n);
    c = getchar();
    for (int i = 0; i != n; i++){
        int index = 0;
        while ((c = getchar()) != '\n'){
            s[index++] = c;
        }
        long long int res = transform(s, index-1);
        printf("case #%d:\n%lld\n", i, res);
        continue;
    }
}