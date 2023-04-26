#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int n[50];
    n[0]=1;
    n[1]=2;
    n[2]=4;
    n[3]=8;
    for(int i=0;i<t;i++){
        int num;
        scanf("%d",&num);
        long long int sum;
        for(int m=4;m<num;m++){
            a[m]=a[m-1]+a[m-2]+a[m-3]+a[m-4];
        }
        printf("case #%d:\n%lld\n",i,a[num-1]);
    }
    return 0;
}

