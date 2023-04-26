#include<stdio.h>
#include<string.h>
void transform(int num, int i){
    int temp = i;
    char bin[temp];
    while(temp){
        bin[--temp] = num % 2;
        num /= 2; 
    }
    for (int j = 0; j != i; j++)
        printf("%d", bin[j]);
}
int main(){
    char code[501];
    scanf("%s", code);
    int len = strlen(code);
    int mod = len % 3;
    printf("0001");
    transform(len, 10);
    for (int i = 0; len > 2 && i != len - mod; i+=3){
        int res = 0;
        for (int j = 0; j != 3; j++)
            res += 10 * res + (code[i+j] - '0');
        transform(res, 10);
    }
    if (mod == 1) transform(code[len-1]-'0', 4);
    if (mod == 2) transform(code[len-1]-'0'+10*(code[len-2]-'0'), 7);
    printf("\n");
    return 0;
}