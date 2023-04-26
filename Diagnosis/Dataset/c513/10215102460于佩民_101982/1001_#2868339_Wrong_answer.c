#include <stdio.h>

int main(){
    int num,N,R,b=0,c=0,i;
    int a[100];
    scanf("%d",&num);
    while(b<num){
        scanf("%d%d",&N,&R);
        if(N<0){
            printf("-");
            N=-N;
        }
        if(N=0){
            printf("0\n");
        }
        if(N>0){
            while(N!=0){
                a[c++]=N%R;
                N/=R;
            }
        }
        b++;
        for(i=c-1;i>=0;i--){
            printf("%d",a[c]);
        }
    }
}

