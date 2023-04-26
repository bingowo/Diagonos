#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[20];
    a[0]=1;
    a[1]=2;
    a[2]=4;
    a[3]=7;
    a[4]=12;
    for(int i=3;i<20;i++){
        a[i]=2*a[i-1]-a[i-4]-a[i-6];
    }
    int n;
    scanf("%d",&n);
    while(n!=-1){
        printf("%d\n",a[n]);
        scanf("%d",&n);
    }
    return 0;
}