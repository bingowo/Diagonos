#include<stdio.h>
int main(){
    int T,R,N,y=1,i=0;
    scanf("%d",&T);
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Ans[32];
    while(T>1){
        scanf("%d%d",&N,&R);
        do{
            y=N%R;
            N/=R;
            Ans[i]=table[y];
            i++;
        }while(y>0);
        int h=i;
        T--;
        for(;i>=0;i--)printf("%c",Ans[h-i]);
    }
}