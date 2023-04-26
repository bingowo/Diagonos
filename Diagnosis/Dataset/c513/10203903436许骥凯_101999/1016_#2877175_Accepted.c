#include<stdio.h>

void reverse(char *res, int len){
    int lo = 0, hi = len - 1;
    while (lo <= hi){
        char temp = res[lo];
        res[lo++] = res[hi];
        res[hi--] = temp;
    }
}

int main(){
    int a, b, idx = 0;
    char res[100], table[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D'
    ,'E','F','G','H','I','J','K','L'};
    scanf("%d %d", &a ,&b);
    do{
        int mod = a % b;
        int div = a / b;
        if (mod < 0){
            mod -= b;
            div++;
        }
        a = div;
        res[idx++] = table[mod]; 
    }while(a);
    reverse(res, idx);
    for (int i = 0; i != idx; i++)
        printf("%c", res[i]);
    printf("\n");
}