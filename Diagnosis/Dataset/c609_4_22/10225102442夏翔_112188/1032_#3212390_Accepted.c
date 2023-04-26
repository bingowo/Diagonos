#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *s;
    int max=1, temp=1;
    s = (char*)malloc(sizeof(char)*51);
    scanf("%s", s);
    for(int i=0; i<strlen(s)-1; i++){
        if(s[i]!=s[i+1]) temp++;
        else{
            max = (temp>max)? temp: max;
            temp = 1;
        }
    }
    max = (temp>max)? temp: max;
    printf("%d", max);
    free(s);
    return 0;
}
