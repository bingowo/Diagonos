#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a, const void* b){
    char* x = *((char**)a);
    char* y = *((char**)b);
    int user_x = (strchr(x, '@')-x)/sizeof(char);
    int user_y = (strchr(y, '@')-y)/sizeof(char);
    if(strcmp(x+user_x, y+user_y) == 0){
        return -strcmp(x, y);
    }
    else{
        return strcmp(x+user_x, y+user_y);
    }

}
int main(){
    int n;
    scanf("%d", &n);
    char** epL = (char**)malloc(sizeof(char*)*n);
    char s[100001];
    char *p;
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        int len = strlen(s);
        p = (char*)malloc(sizeof(char)*(len+1));
        strcpy(p, s);
        *(epL+i) = p;
    }
    qsort(epL, n, sizeof(char*), cmp);
    for(int i = 0; i<n; i++){
        printf("%s\n", *(epL+i));
    }
    return 0;
}
