#include <stdio.h>

int main(){
    int T;
    scanf("%d",&T);
    int a=1,N,R,count=0,i,d;
    while(a<=T){
        scanf("%d%d",&N,&R);
        int b[100];
        if(N<0){
            b[0]='-';
            N=-N;
        }
        do{
            if(N%R<10) b[count++]=N%R;
            if(N%R>=10){
                d=N%R-10;
                b[count++]='A'+d;
            }
            N=N/R;
        }while(N!=0);
        for(i=0;b[i]!='\0';i++){
            printf("%d",b[i]);
        }
        a=a+1;
    }
}

