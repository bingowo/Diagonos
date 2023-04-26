#include<stdio.h>
char* item(int n){
    int p=0;
    char *r;
    while(n){
       *r=n%2333;
       n/=2333;
       *r++=' ';
    }
    return r;
}   
int main(){
    int T,i=0,j=0,p=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        printf("%s",item(n));
        printf("\n");
        }   
    return 0;
}