#include <stdio.h>

int main(){
    char table[]="0123456789ABCDEFGHIJ";
    int N,R;
    int i=0;
    int a[10000];
    scanf("%d %d\n",&N,&R);
    a[0]=0;
    for(;N!=0;i++){
        if(N<0){
            if(N%R==0){
                a[i]=N%R;
                N=N/R;
            }
            else {
                a[i] = N % R - R;
                N = N / R + 1;
            }
        }
        else{
            a[i]=N%R;
            N/=R;
        }
    }
    i--;
    for(;i>=0;i--)
        printf("%c",table[a[i]]);
    return 0;
}