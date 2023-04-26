#include <stdio.h>
#include <stdlib.h>

int number(int a){
    int count=0,b=1;
    for(int j=0;j<64;j++){
        if(a&b){count++;}
        else count=count+0;
        b=(b<<1);
    }
    return count;
}

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    temp=*b;
}

int b_sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(number(a[j])<number(a[j+1])){
                swap(&a[i],&a[i+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(number(a[i])==number(a[i+1]) && a[i]>a[i+1]){
            swap(&a[i],&a[i+1]);
        }
    }
}

int main(){
    int T,N,a[10001],i,j,b[10][10001],k;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&N);
        for(j=0;j<N;j++){
            scanf("%d",&a[j]);
        }
        b_sort(a,N);
        for(k=0;k<N;k++){
            b[i][k]=a[k];
        }
    }
    for(i=0;i<T;i++){
        printf("case #%d:\n",i);
        for(j=0;j<N;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}