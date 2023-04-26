#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        char a[100];
        int j=0;
        while(x){
        a[j]=x%2;
        x=x/2;
        }
        int a1=strlen(a);
        char b[100];
        int k=0;
        while(y){
        a[k]=y%2;
        y=y/2;}
        int b1=strlen(b);
        int n=0;
        for(int m=0;m<abs(a1-b1);m++){
            if(a[m]!=b[m])n=n+1;
        }
        n=n+abs(a1-b1);
        printf("%d\n",n);


    }
    return 0;
}
