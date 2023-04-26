#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    int a=1,N,R,count=0,i;
    while(a<=T){
        scanf("%d%d",&N,&R);
        int b[100];
        do{
            b[count++]=N%R;
            N=N/p;
        }while(N!=0);
        for(i=0;b[i]!='\0';i++){
            printf("%d",b[i]);
        }
        a=a+1;
    }
}

