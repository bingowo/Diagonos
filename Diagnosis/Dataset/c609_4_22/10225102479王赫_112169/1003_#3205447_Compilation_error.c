#include<stdio.h>
int main(){
    int T,i=0,j=0,p=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int n,m[50];
        scanf("%d",&n);
        while(n){
           m[p]=(n%2333);
           n/=2233;
           p++;}
        for(j=p-1;j>=0;j--){
           printf("%d",m[j]);
           printf("\t");}
        printf("\n");
        }   
    }
    return 0;
}