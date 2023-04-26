#include <stdio.h>
#include <stdlib.h>

int cmpA(const void* e1,const void* e2){
    return *(int*)e1 - *(int*)e2;
};


int main() {
    char loop;
    scanf("%d", &loop);

    int arr[100] = {0};
    int i = 0;

    for (; i < loop; ++i) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, i, sizeof(int), cmpA);

    int answer = 0;
    for (int j = 0; j < i-1;j++) {
        int plus = (arr[j + 1] - arr[j]);
        plus = plus ? plus : -plus;
        answer = answer + plus;
        j++;
    }printf("%d",answer);
}