#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *s = (char*)malloc(sizeof(char) * 100001);
    int a[128]; 
    for (int i = 0; i <= 128; i++){
        if (i >= 'a' && i <= 'f') a[i] = 10 + i - 'a';
        else if (i >= '0' && i <= '9') a[i] = i - '0';
        else a[i] = -1;
    }
    scanf("%s", s); 
    printf("%d", a[0]);
    // unsigned int sum = 0; int i = 0, flag = 1;
    // // for (; i < strlen(s); i++){
    // //     if (s[i] == 'x' && s[i-1] == '0'){
    // //         flag = 0; i++;
    // //         //while(i < strlen(s) && table[s[i]] != -1)
    // //             //sum = table[s[i++]] + sum * 16;
    // //         printf("%d ", sum);
    // //         sum = 0;
    // //     }
    // // }
    // if (flag) printf("-1\n");
    // free(s);
    return 0;
}
