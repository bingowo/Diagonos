#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    int T;
    scanf("%d", &T);
    int n, m, L, U, temp=0, len;
    int *num, *arr;
    int sum;
    for(int k=0 ; k<T; k++){
        scanf("%d %d", &n, &m);
        temp = 0;
        len = n*(n+1)/2;
        num = (int*)malloc(sizeof(int)*n);
        arr = (int*)malloc(sizeof(int)*len);
        for(int i=0; i<n; i++){
            scanf("%d", &num[i]);
            arr[i] = num[i]; 
        }
        for(int i=n; i>1; i--){
            for(int j=n-i+1; j<n;j++){
                arr[temp+i+j-n+i-1] = arr[temp+j-n+i-1]+num[j];
            }
            temp+=i;
        }
        qsort(arr,len,sizeof(arr[0]),cmp1);
        printf("case #%d:\n", k);
        for(int i=0; i<m; i++){
            sum = 0;
            scanf("%d %d", &L, &U);
            for(int j=L-1; j<U; j++){
                sum += arr[j];
            }
            printf("%d\n", sum);
        }
        free(num);
        free(arr);
    }



    return 0;
}