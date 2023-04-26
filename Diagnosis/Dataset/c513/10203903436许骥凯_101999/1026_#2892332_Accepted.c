#include<stdio.h>
#include<stdlib.h>

int compare(const void *p1, const void *p2){
    return *(int*)p2 - *(int*)p1;
}

void output(int *numbers, int n){
    int sum = 0, i = 0;
    for (; i < n - 1; i += 2)
        sum += numbers[i] - numbers[i+1];
    if (i == n - 1) sum += numbers[n-1];
    printf("%d\n", sum);
    free(numbers);
}

int main(){
    int n;
    scanf("%d", &n);
    int *numbers = (int*)malloc(sizeof(int) *n);
    for (int i = 0; i != n && scanf("%d", &numbers[i++]););
    qsort(numbers, n, sizeof(numbers[0]), compare);
    output(numbers, n);
    return 0;
}