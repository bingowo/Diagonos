#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        double res = 0; 
        char num[53];
        scanf("%s", num);
        for (int j = strlen(num) - 1; j != 1; j--)
            res = res / 8 + (num[j] - '0');
        res /= 8;
        printf("case #%d:\n0.", i);
        for (int j = 0; j != 3 * (strlen(num) - 2); j++){
            res *= 10;
            int temp = res;
            printf("%d", temp);
            res -= temp;
        }
        printf("\n");
    }
    return 0;
}