#include<stdio.h>

void add(int a[], int b[]){
    for (int i=0; i<50; i++){
        a[i]+=b[i];
        if (a[i]>=10){
            a[i+1]++;
            a[i]-=10;
        }
    }
    return;
}

void minus(int a[], int b[]){
    for (int i=0; i<50; i++){
        a[i]-=b[i];
        if (a[i]<0){
            a[i+1]--;
            a[i]+=10;
        }
    }
    return;
}
int main(){
    int k, n;
    scanf("%d %d", &k, &n);
    int arr[115][50]={0};
    arr[11][0]=1;
    for (int i=3; i<=k; i++){
        for (int j=1; j<=k; j++) {
            add(arr[9+i], arr[9+i-j]);
        }
    }
    for (int i=k+1; i<=n; i++){
        add(arr[9+i], arr[9+i-1]);
        add(arr[9+i], arr[9+i-1]);
        minus(arr[9+i], arr[9+i-1-k]);
    }
    int index=49;
    while(index>=0 && arr[9+n][index]==0) index--;
    if (index<0) printf("0");
    for (int i=index; i>=0; i--) printf("%d", arr[9+n][i]);
    printf("\n");
    return 0;
}