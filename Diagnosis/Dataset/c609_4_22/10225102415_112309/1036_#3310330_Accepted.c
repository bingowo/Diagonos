#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>
int stack;
int value(int left,int right,char* s) {
    if (left == right - 1) {     //到头了
        return 1;
    }else if(left>=right){          //后面没了
        return 0;
    }else {
        stack += 1;
        for (int i = left + 1; i <= right; i++) {
            if (s[i] == '(') {
                stack++;
            }else {
                stack--;
            }
            if (stack == 0&&left!=i-1) {
                return(2 * value(left + 1, i-1,s) + value(i + 1, right,s));
            }else if(stack == 0){
                return ( 1+ value(i + 1, right,s));///////
            }
        }
    }
}
int main() {
    char* s;
    s = malloc(105);
    scanf("%s",s);
    int b=strlen(s);
    int a = value(0, b-1,s);
    printf("%d", a);
    return 0;
}
