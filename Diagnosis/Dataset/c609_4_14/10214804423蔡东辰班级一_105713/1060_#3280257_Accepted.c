#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[101] = {0};
    scanf("%s", s);
    int len = strlen(s);
    int* array = (int*)malloc(sizeof(int) * len);
    for(int i = 0; i<len; i++){array[i] = 0;}
    for(int i = 0; i<len; i++){
        if(s[i]<s[i+1]){
            array[i] = 1;
        }
        else if(s[i] == s[i+1]){
            int cnt = 0;
            for(int j = i+1; j<len; j++){
                if(s[j] == s[j+1]){
                    continue;
                }
                else if(s[j]>s[j+1]){
                    break;
                }
                else if(s[j] < s[j+1]){
                    cnt = j+1 - i;
                    break;
                }
            }
            for(int j = 0; j<cnt; j++){
                array[i+j] = 1;
            }
            i += (cnt>0)?cnt-1:0;
        }
    }
    for(int i = 0; i<len; i++){
        if(array[i]){
            printf("%c%c", s[i], s[i]);
        }
        else{
            printf("%c", s[i]);
        }
    }
    free(array);
    return 0;
}