#include <stdio.h>
#include <stdlib.h>

int cmpA(const void* e1,const void* e2){
    return *(int*)e1 - *(int*)e2;
};


int main() {
    char loop;
    scanf("%c", &loop);

    int arr[100] = {0};
    int i = 0;

    do {
        scanf("%d", &arr[i]);
        i++;
    } while (getchar() != '\n');

    qsort(arr, i, sizeof(int), cmpA);

    int answer = 0;
    for (int j = 0; j < i-1;j++) {
        answer = answer + (arr[j + 1] - arr[j]);
        j++;
    }printf("%d",answer);
}