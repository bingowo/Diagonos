#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[20];
    a[0]=0;
    a[1]=2;
    a[2]=4;
    int abs=8;
    for(int i=3;i<20;i++){
        a[i]=abs-a[2*(i-3)];
        abs=abs*2;
    }
    int n;
    scanf("%d",&n);
    while(n!=-1){
        printf("%d\n",a[n]);
        scanf("%d",&n);
    }
    return 0;
}