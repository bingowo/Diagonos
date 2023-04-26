#include <stdio.h>
#include <stdlib.h>

int compar(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size){
    int *retArr = (int *)malloc(sizeof(int) * arr1Size);
    int index = 0;
    qsort(arr1, arr1Size, sizeof(int), compar);
    for(int i = 0; i < arr2Size; i++) {
        for(int j = 0; j < arr1Size; j++) {
            if(arr1[j] == arr2[i]) {
                retArr[index++] = arr1[j];
                arr1[j] = 1001;
            }
        }
    }
    for(int i = 0; i < arr1Size; i++) {
        if(arr1[i] <= 1000) {
            retArr[index++] = arr1[i];
        }
    }
    return retArr;
}

int main(){
    int m,n,i;
    int a[1001],b[1001];
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int *j=relativeSortArray(b, n, a, m);
    for(i=0;i<n;i++){
        printf("%d ",*(j++));
    }
    return 0;
}
