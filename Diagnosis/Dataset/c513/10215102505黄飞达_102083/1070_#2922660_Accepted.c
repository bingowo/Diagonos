#include<stdio.h>
#include<math.h>

int mypow(int a, int b){
    int res = 1;
    for (int i = 1; i <= b; i++) {
        res *= a;
    }
    return res;
}

int check(int arr[], int n){
    for (int i = 0; i+2 < n; i++){
        if (arr[i]==1&&arr[i+1]==0&&arr[i+2]==1) return 0;
    }
    return 1;
}

int main(){
    int n;
    while (scanf("%d", &n)!=EOF){
        if (n==-1) break;
        int max = mypow(2, n), count = 0;
        for (int i = 0; i < max; i++) {
            int arr[21] = {0};
            for (int j = 0; j < n; j++) {
                arr[j] = (i>>(n-j-1))&1;
            }
            if (check(arr, n)==1) count++;
        }
        printf("%d\n", count);
    }
    
    return 0;
}