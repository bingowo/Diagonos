#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpa(const void*a, const void*b){
    int x = *(int*)a;
    int y = *(int*)b;
    return x < y ? -1 : 1;
}

int cmpd(const void*a, const void*b){
    int x = *(int*)a;
    int y = *(int*)b;
    return x < y ? 1 : -1;
}
int main(){
    int arr[1001] = {0};
    char ch;
    scanf("%c ", &ch);
    int temp;
    while (scanf("%d", &temp) != EOF) arr[temp]++;
    int res[101] = {0};
    int index = 0;
    for (int i = 0; i < 1001; i++){
        if (arr[i] > 0) res[index++] = i;
    }
    if (ch == 'A') qsort(res, index, sizeof(int), cmpa);
    else if (ch == 'D') qsort(res, index, sizeof(int), cmpd);
    for (int i = 0; i < index; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}