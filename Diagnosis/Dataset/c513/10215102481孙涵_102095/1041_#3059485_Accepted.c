#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int length = 1;
    int max = 0;
    for(int i = 0; i < strlen(s); i++){
        for(int j = i; j < strlen(s) - 1; j++){
            if(s[j] != s[j+1]){
                length++;
            }else{
                break;
            }
        }
        if(length > max){
            max = length;
        }
        length = 1;
    }
    printf("%d",max);
    return 0;
}
