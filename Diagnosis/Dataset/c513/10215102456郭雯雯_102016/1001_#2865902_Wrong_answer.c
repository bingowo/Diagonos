#include<stdio.h>
int main(){
    int T,R,N,y=1,i=0;
    scanf("%d",&T);
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Ans[32];
    while(T>0){
        scanf("%d%d",&N,&R);
        if(N<0){
            N*=(-1);printf("-");
        }
        do{
            y=N%R;
            N/=R;
            Ans[i]=table[y];
            i++;
        }while(N>0);
        for(;i>=0;i--)printf("%c\n",Ans[i]);
        T--;
    }
}