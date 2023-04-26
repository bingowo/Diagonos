#include<stdio.h>

int main(){
    int res = 1;
    char c; scanf("%c", &c);
    int len = 1;
    while(c != '\n'){
        char temp; 
        scanf("%c", &temp);
        if (temp == c || temp == '\n'){
            if (len > res) res = len;
            len = 1;
        }
        else len++;
        c = temp;
    }
    printf("%d\n", res);
}