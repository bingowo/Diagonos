#include <stdio.h>
#include <stdlib.h>

void reverse_and_print(int *s, int len){
    for(int i = len-1; i >= 0; i--){
        printf("%d",s[i]);
    }
}

int main()
{
    char arr[501];
    int s[10];
    scanf("%s",&arr);
    int a, b, c, i, j, pos = 1;
    a = strlen(arr);
    b = strlen(arr)%3;
    printf("0001");
    for(i = 0; i < 10; i++){
        if(a&pos) s[i] = 1;
        else s[i] = 0;
        pos = pos<<1;
    }
    reverse_and_print(s,10);
    for(i = 0; i < a-b; i += 3){
        c = (arr[i]-'0')*100+(arr[i+1]-'0')*10+arr[i+2]-'0';
        pos = 1;
        for(j = 0; j < 10; j++){
            if(c&pos) s[j] = 1;
            else s[j] = 0;
            pos = pos<<1;
        }
        reverse_and_print(s,10);
    }
    if(b == 1){
        c = arr[i]-'0';
        pos = 1;
        for(j = 0; j < 4; j++){
            if(c&pos) s[j] = 1;
            else s[j] = 0;
            pos = pos<<1;
        }
        reverse_and_print(s,4);
    }
    if(b == 2){
        c = (arr[i]-'0')*10+arr[i+1]-'0';
        pos = 1;
        for(j = 0; j < 7; j++){
            if(c&pos) s[j] = 1;
            else s[j] = 0;
            pos = pos<<1;
        }
        reverse_and_print(s,7);
    }
    return 0;
}