#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct{
    int data_value[100];
}rows_data;

int cmp(const void *a, const void *b){
    int i = 0;
    rows_data * pa = (rows_data *)a;
	rows_data * pb = (rows_data *)b;
    while (pa->data_value[i] != -1 && pb->data_value[i] != -1){
        if(pa->data_value[i] > pb->data_value[i]) return -1;
        else if(pa->data_value[i] < pb->data_value[i]) return 1;
        else i++;
    }
    if(pa->data_value[i] == -1) return 0;
    else return 1;
}

void solve(int T){
    int N;
    scanf("%d", &N);
    rows_data rowsData[1000];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 100; ++j) {
            scanf("%d", &rowsData[i].data_value[j]);
            if(rowsData[i].data_value[j] == -1) break;
        }
    }
    qsort(rowsData,N,sizeof(rowsData[0]),cmp);
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < 100; ++j){
            if(rowsData[i].data_value[j] == -1) break;
            printf("%d ",rowsData[i].data_value[j]);
        }
        printf("\n");
    }
}

int main(){
    int issue_num;
    scanf("%d", &issue_num);
    for (int i = 0; i < issue_num; ++i) {
        solve(i);
    }
    return 0;
}