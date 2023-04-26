#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *s, *pos, *maxs;
    s = (char*)malloc(sizeof(char)*1000001);
    maxs = (char*)malloc(sizeof(char)*1000001);
    scanf("%s", s);
    int len=strlen(s), max=1;
    strcpy(maxs,s+len-1);
    for(int i=len-2; i>=0; i--){
        if(strchr(s+i+1,s[i])){
            pos = strchr(s+i+1,s[i]);
            pos[0] = '\0';
        }
        if(strlen(s+i)>=max){
            strcpy(maxs,s+i);
            max = strlen(maxs);
        }
    }
    printf("%s", maxs);
    free(s);
    free(maxs);
    return 0;
}