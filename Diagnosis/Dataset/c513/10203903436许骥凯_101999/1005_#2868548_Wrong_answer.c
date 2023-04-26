#include<stdio.h>
#include<stdlib.h>
int main(){
    char num;
    int n;
    scanf("%d", &n);
    num = getchar();
    for (int i = 0; i != n; i++){
        double res = 0; 
        int fac = 8, cnt = 0;
        num = getchar(); num = getchar();
        while ((num = getchar()) != EOF){
            if (num == '\n'){
                printf("case #%d:\n0.", i);
                for (int j = 0; j != 3 * cnt; j++){
                    res *= 10;
                    int temp = res;
                    printf("%d", temp);
                    res -= temp;
                }
                printf("\n");
                break;
            }
            res = (num - '0') * 1.0 / fac + res;
            fac *= 8; 
            cnt++;
        }
    }
    return 0;
}