#include <stdio.h>
#include <stdlib.h>
    int * add(int* e1,int* e2){
    for(int j=0;j<=99;j++){
    e1[j]=e1[j]+e2[j];
    }
    int carry;
    for(int j=0;j<=98;j++){
    carry=e1[j]/10;
    e1[j+1]+=carry;
    e1[j]=e1[j]%10;
    }
    return e1;
    }
    int* fib(int e){
    if(e==0){
    int a[100]={1};
    return  ;
    }else if(e==1||e==2){
    int b[100]={1};
    return b;
    }else{

    return add(fib(e-1),fib(e-2));
    }



    }



    int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    int t;
    scanf("%d",&t);
    int sum[100]={0};
    if(t==0){
    printf("0\n");
    }else if(t==1||t==2){
    printf("1\n");
    }else{
    int * res=fib(t);
    int l;
    for(l=99;l>=0;l--){
    if(res[l]!=0) break;
    }
    for(;l>=0;l--){
    printf("%d",res[l]);

    }
    printf("\n");

    }



    }




    }
