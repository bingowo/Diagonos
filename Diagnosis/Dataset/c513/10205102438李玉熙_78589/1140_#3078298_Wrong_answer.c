#include<stdio.h>
int main() {
    int a[10000],b[1000]={0};
    int n,d,num=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        for(int j=0;j<d;j++) {
            scanf("%d", &a[num]);
            num++;
        }
    }
    for(int m=0;m<=num;m++){
        b[a[m]]++;
    }
    for(int i=0;i<1000;i++){
        if(b[i]==n)printf("%d ",i);
    }
    return 0;
}