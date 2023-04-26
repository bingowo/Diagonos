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
        j++;
        }
        char b[100];
        int k=0;
        while(y){
        a[k]=y%2;
        y=y/2;
        k++;
        }
        int n=0;
        int p;
        if(j-k>0)p=k;
            else p=j;
        for(int m=0;m<p;m++){
            if(a[p-m]!=b[p-m])n=n+1;
        }
        n=n+abs(j-k);
        printf("%d\n",n);}


    return 0;
}
