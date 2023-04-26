#include<stdio.h>
#include<stdlib.h>

typedef struct numi{
    int a1,x1;
}num;

num* slove_i(int n){
    num* sta;
    sta = (num*)malloc(sizeof(num));
    if(n==0) {sta->a1=1;/*sta->a2=0;*/sta->x1=0;/*sta->x2=0;*/}
    else if(n==1) {sta->a1=0;/*sta->a2=0;*/sta->x1=1;/*sta->x2=1;*/}
    else{ sta->a1=slove_i(n-1)->a1+slove_i(n-2)->a1;
          sta->x1=slove_i(n-1)->x1+slove_i(n-2)->x1;
        }
    return sta;
}

int slovex (int n,int a,int m,int x){
    num* sta1,*sta2;
    sta1 = (num*)malloc(sizeof(num));
    sta2 = (num*)malloc(sizeof(num));
    sta1->a1=1;
    sta1->x1=0;
    int i;
    for(i=2;i<n-1;i++){
        sta1->a1 += slove_i(i-2)->a1;
        sta1->x1 += slove_i(i-2)->x1;
        if(i==x-1){
            sta2->a1=sta1->a1;
            sta2->x1=sta1->x1;
        }
    }
    int xi = (m-a*sta1->a1)/sta1->x1;
    printf("%d ",xi);
    return sta2->a1*a+sta2->x1*xi;
}

int main(){
    int a=3,n=5,m=12,x=3;
    scanf("%d %d %d %d",&a,&n,&m,&x);

    printf("%d",slovex(n,a,m,x));
    return 0;
}
