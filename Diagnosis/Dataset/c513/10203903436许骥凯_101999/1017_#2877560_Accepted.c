#include<stdio.h>
#include<string.h>
int main(){
    int table[128];
    table['I'] = 1, table['V'] = 5, table['X'] = 10, table['L'] = 50,
    table['C'] = 100, table['D'] = 500, table['M'] = 1000;
    char roma[51] = {0};
    scanf("%s", roma);
    int len = strlen(roma);
    long long int sum = 0, mod = 0;

    int index = len - 1;
    while (roma[index] != ')' && index >= 0){
        if (roma[index] == roma[index + 1]) mod += table[roma[index]];
        else if (mod <= table[roma[index]]) mod += table[roma[index]];
        else mod -= table[roma[index]];
        index--;
    }

    for (int i = index; i >= 0; i--){
        if (roma[i] == ')') continue;
        else if (roma[i] == '(') {sum *= 1000; continue;}
        else if (roma[i] == roma[i+1]) sum += table[roma[i]];
        else if (sum <= table[roma[i]]) sum += table[roma[i]];
        else sum -= table[roma[i]];

    }
    printf("%lld\n", sum + mod);
}