#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int num, bin[32];
        scanf("%d", &num);
        int index = 0;
        do{
            bin[index++] = num % 2;
            num /= 2;
        }while(num);

        int max = 1;
        for (int j = 0, count = 1; j != index-1; j++){
            if (bin[j] != bin[j+1]) count++;
            else count = 1;
            max = (max > count)? max: count;
        }
        printf("case #%d:\n%d\n", i, max);
    }
    return 0;
}