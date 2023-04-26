#include<stdio.h>
int main(){
    int T,i;
    scanf("%d",&T);
    int x,a[100];
    while(T--){
        i=0;
        scanf("%d",&x);
        while(x){
            a[i++]=x%2333;
            x/=2333;
        }
        for(int j=i-1;j>=0;j--)
            printf("%d ",a[j]);
        printf("\n");
    }
    return 0;
}