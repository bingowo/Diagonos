#include<stdio.h>
char** item(int n){
    int p=0,r[50];
    while(n){
       r[p++]=n%2333;
       n/=2333;
       r[p]='';
    }
    return r;
}   
int main(){
    int T,i=0,j=0,p=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("%s",item(n));}
        printf("\n");
        }   
    return 0;
}