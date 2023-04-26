#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct str{
    char s[21];
    int count;
}str;


int cmp(const void *a, const void *b){
    str *x = (str*)a;
    str *y = (str*)b;
    if (x->count != y->count) return y->count-x->count;
    else return strcmp(x->s, y->s);
}

int main(){
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        int n;
        scanf("%d", &n);
        str strarr[101];
        for (int i = 0; i < n; i++){
            str s0;
            s0.count=0;
            scanf("%s", &s0.s);
            int arr[128] = {0};
            for (int j = 0; j < 128; j++){
                if (arr[s0.s[j]] == 0){
                    s0.count++;
                    arr[s0.s[j]]++; 
                }
            }
            strarr[i] = s0;
        }
        qsort(strarr, n, sizeof(str), cmp);
        printf("case #%d:\n", t);
        for (int i = 0; i < n; i++) printf("%s\n", strarr[i].s);


    }
    return 0;
}