#include<stdio.h>
int main(){
    int T,R,N;
    scanf("%d",&T);
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char Ans[32];
    while(scanf("%d%d",&N,&R)!=EOF){
        int y=0,i=0;
        if(N<0){
            N*=-1;printf("-");
        }
        do{
            y=N%R;
            N/=R;
            Ans[i]=table[y];
            i++;
        }while(N>0);
        for(;i>=0;i--)printf("%c",Ans[i]);
        printf("\n");
    }
    return 0;
}