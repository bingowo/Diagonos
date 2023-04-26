#include<stdio.h>
int main(){
    int T,i=0,j=0,p=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        while(n){
           int m[50];
           m[p]=(n%2333);
           n/=2233;
           p++;
        }
        for(j=p-1;j>=0;j--){
           printf("%d\t",m[j]);}
        printf("\n");
        }   
    return 0;
}