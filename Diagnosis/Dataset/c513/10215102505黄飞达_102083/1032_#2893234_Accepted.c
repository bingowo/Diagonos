#include<stdio.h>
#include<stdlib.h>

typedef struct what{
    int *arr;
    int len;
}what;

int cmp(const void* a, const void* b){
    what* x = (what*)a;
    what* y = (what*)b;
    for (int i = 0, j = 0; i < x->len, j < y->len; i++, j++){
        if (x->arr[i] != y->arr[j]) return - x->arr[i] + y->arr[j];
    }
    return - x->len + y->len;
}

int main(){
    int n, T;;
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        scanf("%d", &n);
        what whatarr[n];
        for (int i = 0; i < n; i++){
            what w;
            w.arr = (int*)malloc(4);
            int temp = 0, index = 0;
            while (scanf("%d", &temp)){
                if (temp == -1) break;
                w.arr[index++] = temp;
                w.arr = (int*)realloc(w.arr, (index+1)*sizeof(int));
            }
            w.len = index;
            whatarr[i] = w;
            //free(w.arr);
            
        }
        qsort(whatarr, n, sizeof(what), cmp);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < whatarr[i].len; j++){
                printf("%d ", whatarr[i].arr[j]);
            }
            printf("\n");
        }
    }
    return 0;
}