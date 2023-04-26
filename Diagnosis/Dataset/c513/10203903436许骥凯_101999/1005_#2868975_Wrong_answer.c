#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Print(char *res, int len, int times){
    printf("case #%d:\n0.", times);
    for (int i = 0; i != len; i++)
        printf("%c", res[i]);
    printf("\n");
}

void transform(char *num, int len, int times){
    char decimal[153];
    for (int i = 0; i != 154; i++)
        decimal[i] = '0';
    int index;
    for (int i = len - 1; i != 1; i--){
        index = 0; 
        int temp = num[i] - '0';
        for (; index != 3 * (len-i);){
            int mod = decimal[index] - '0';
            int res = (temp * 10 + mod) / 8;
            decimal[index++] = res + '0';
            temp = (temp * 10 + mod) % 8;
        }
    }    
    Print(decimal, index, times);
}

void getOct(int i){
    char num[51];
    scanf("%s", num);
    transform(num, strlen(num), i);
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++)
        getOct(i);
    return 0;
}