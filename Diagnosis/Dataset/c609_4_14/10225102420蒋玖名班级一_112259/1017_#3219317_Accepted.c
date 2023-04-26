#include <stdio.h>
void sortA(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sortD(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int removeDuplicates(int arr[], int size) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size;) {
            if (arr[j] == arr[i]) {
                for (k = j; k < size; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }
    return size;
}
int main() {
    int arr[100];
    char s;scanf("%c",&s);
    int i=0;
    do{
        scanf("%d",&arr[i]);
        i++;
    }
    while(getchar()==' ');
    int size=i;
    if(s=='A') sortA(arr,size);
    else sortD(arr,size);
    size = removeDuplicates(arr, size);
    for (int i = 0; i < size-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n",arr[size-1]);
    return 0;
}
