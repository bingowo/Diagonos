#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sort(const void * a, const void * b);

int main() {

    int i = 0;
    int n;//array number
    scanf("%d",&n);
    int arr[n];
    int *a = arr;
    char c;
	while(i < n){
            scanf("%d",a);
            a++;
            i++;
	}
	qsort(arr,n,4,sort);
	int index = 0;
	int answer = 0;
    while(index < n){
        int x = arr[index++];
        int y = arr[index++];
        answer = answer + (-1) * (y - x);
    }
    printf("%d",answer);
	return 0;
}
int sort(const void * a, const void * b){
     return ( *(int*)b - *(int*)a);
}
