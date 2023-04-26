#include <stdio.h>
int main() {
    int a[21]={0,1,2,4}; //以0结尾
    int b[21]={0,1,2,3}; //以1结尾
    for(int i=4;i<21;i++){
        a[i]=b[i-1]+a[i-1];
        b[i]=b[i-1]+a[i-1]-b[i-2];
    }
    int n;
    scanf("%d",&n);
    do {
        printf("%d\n",a[n]+b[n]);
        scanf("%d",&n);
    } while (n!=-1);
    return 0;
}