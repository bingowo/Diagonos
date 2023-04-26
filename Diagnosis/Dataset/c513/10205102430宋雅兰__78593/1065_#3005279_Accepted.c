#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int a1,x1,a2,x2;
}num;
/*
num* slove_i(int n){
    num* sta;
    sta = (num*)malloc(sizeof(num)); 
    if(n==0) {sta->a1=1;sta->x1=0;}
    else if(n==1) {sta->a1=0;sta->x1=1;}
    else{ sta->a1=slove_i(n-1)->a1+slove_i(n-2)->a1;
          sta->x1=slove_i(n-1)->x1+slove_i(n-2)->x1;
        }
    return sta;
} */

num* slove_i(int n){
    num* sta,*staa,*sta2;
    sta2 = (num*)malloc(sizeof(num)); 
    sta = (num*)malloc(sizeof(num)); 
    staa = (num*)malloc(sizeof(num));
    if(n==2) {sta->a1=2;sta->x1=0;sta->a2=0;sta->x2=1;}
    else if(n==3) {sta->a1=2;sta->x1=1;sta->a2=1;sta->x2=1;}
    else{ 
          staa = slove_i(n-1);
          sta2 = slove_i(n-2);
          sta->a1 = staa->a1+staa->a2;
          sta->x1 = staa->x1+staa->x2;
          sta->a2 = staa->a2+sta2->a2;
          sta->x2 = staa->x2+sta2->x2;
        }
    return sta;
} 

int slovex (int n,int a,int m,int x){
    if(x-1==0) return a;
    else if(x-1==1) return a;
    num* sta1,*sta2;
    sta1 = (num*)malloc(sizeof(num));
    sta2 = (num*)malloc(sizeof(num));
    sta1 = slove_i(n-2);
    sta2 = slove_i(x-1);
    /*
    int i;
    for(i=2;i<n-1;i++){
        sta1->a1 += slove_i(i-2)->a1;
        sta1->x1 += slove_i(i-2)->x1;
        if(i==x-1){
            sta2->a1=sta1->a1;
            sta2->x1=sta1->x1;
        }
    }  */
    int xi = (m-a*sta1->a1)/sta1->x1;
   // printf("%d_",xi);
    return sta2->a1*a+sta2->x1*xi;
}

int main(){
    int a=5,n=7,m=32,x=4;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    printf("%d",slovex(n,a,m,x));
    return 0;
}
