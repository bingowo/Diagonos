#include<stdio.h>
#define L 40

int main(){
    int A,B,log3[20],n;
    scanf("%d %d",&A,&B);
    log3[0]=1;
    for(int i=1;i<20;i++)log3[i]=3*log3[i-1];
    for(int i=0;i<20;i++)if(B==log3[i]){n=i;break;}
    int a=A/B,b=A%B,ite[20]={0},xia[20]={0},ans[50]={0};
    for(int i=0;b>0;i++){
        xia[i]=b%3;b/=3;
    }
    for(int i=0;a>0;i++){
        ite[i]=a%3;a/=3;
    }
}