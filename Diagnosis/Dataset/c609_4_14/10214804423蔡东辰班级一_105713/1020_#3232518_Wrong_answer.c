#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp_str(const void* a, const void* b){
    char* x = *((char**)a);
    char* y = *((char**)b);
    return strcmp(x, y);
}
int cmp_num(const void* a, const void* b){
    char* x = *((char**)a);
    char* y = *((char**)b);
    int x_num = 0;
    int y_num = 0;
    int x_len = strlen(x);
    int y_len = strlen(y);
     for(int i = 0; i < x_len; i++){
        if(x[i]-'0'<10 && x[i]-'0' >= 0){
            x_num = x[i]-'0' + x_num*10;
        }
    }
    for(int i = 0; i < y_len; i++){
        if(y[i]-'0'<10 && y[i]-'0' >= 0){
            y_num = y[i]-'0' + y_num*10;
        }
    }
    return x_num - y_num;
}
int main(){
    char** L = (char**)malloc(sizeof(char*)*100);
    char** num = (char**)malloc(sizeof(char*)*100);
    char s[5000];
    char c;
    int si = 0;
    int numi = 0;
    char *p;
    for(int i = 0; i < 101; i++){
        int judge = 1;
        scanf("%s", s);
        int len = strlen(s);
        for(int j = len-1; j > -1; j--){
            if(s[j]-'0'<10 && s[j]-'0'> 0){
                p = (char*)malloc(sizeof(char)*(len+1));
                strcpy(p, s);
                *(num+numi) = p;
                numi++;
                judge = 0;
                break;
            }
        }
        if(judge==1){
            p = (char*)malloc(sizeof(char)*(len+1));
            strcpy(p, s);
            *(L+si) = p;
            si++;
        }
        if(c=getchar() == '\n'){
            break;
        }
    }
    qsort(L, si, sizeof(char*), cmp_str);
    qsort(num, numi, sizeof(char*), cmp_num);
    for(int i = 0; i < si; i++){
        printf("%s ", *(L+i));
    }
    for(int i = 0; i < numi; i++){
        printf("%s ", *(num+i));
    }
    return 0;
}
