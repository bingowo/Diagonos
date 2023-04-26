#include<stdio.h>
#include<stdlib.h>
int main(){
    int T,N,R,a[33];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    scanf("%d",&T);
    for(int k=0;k<T;k++){
        scanf("%d%d",&N,&R);
        flag=0;
        if(N<0){
            n=-n;
            flag=1;
        }
        int i=0;
        do{ a[i]=N%R;
            i++;
            N=N/R;
        }
        while(N);
    }
    if(flag)
        printf("-");
    for(int j=k-1;j>=0;j--)printf("%c",table[a[i]]);
    printf("\n");
    return 0;

}