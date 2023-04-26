#include<stdio.h>
char* item(int n){
    int p=0,count=0;
    char *r=(char *)malloc(50*sizeof(char));
    for(p=0;n;p+=2){
        *(r+p) = n%2333;
        n/=2333;
        count+=2;
        if(n==0) break;
        else *(r+p+1) =' ';
       }
     for(p=count-2;p>=0;p--){
         return *(r+p);
     }
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