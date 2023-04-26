#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char str[21];
    int table[100];//映射表
    int cnt;
}S;
static int cmp(const void* a, const void* b){
    S x = *((S*)a);
    S y = *((S*)b);
    if(x.cnt == y.cnt){
        return strcmp(x.str, y.str);
    }
    return y.cnt - x.cnt;
}
int main(){
    int T, n, len;
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
        scanf("%d", &n);
        S* array = (S*)malloc(sizeof(S)*n);
        for(int j = 0; j<n; j++){
            scanf("%s", array[j].str);
            len = strlen(array[j].str);
            for(int k = 0; k<100; k++){
                array[j].table[k] = 0;
            }
            for(int k = 0; k<len; k++){
                array[j].table[array[j].str[k]]++;
            }
            array[j].cnt = 0;
            for(char x ='A'; x<='Z'; x++){
                if(array[j].table[x]){
                    array[j].cnt++;
                }
            }
        }//输入
        qsort(array, n, sizeof(S), cmp);
        printf("case #%d:\n", i);
        for(int j = 0; j<n; j++){
            printf("%s\n", array[j].str);
        }
        free(array);
    }
    return 0;
}