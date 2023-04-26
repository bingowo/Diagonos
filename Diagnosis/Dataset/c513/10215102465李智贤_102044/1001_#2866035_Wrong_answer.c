#include<stdio.h>
#include<stdlib.h>
int main(){
    int T,N,R,a[33],j,k,flag=0;
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    scanf("%d",&T);
    for(k=0;k<T;k++){
        scanf("%d%d",&N,&R);
        
        if(N<0){
            N=-N;
            flag=1;
        }
        int i=0;
        do{ a[i]=N%R;
            i++;
            N=N/R;
        }
        while(N);
    
    if(flag)
        printf("-");
    for(j=i-1;j>=0;j--)printf("%c",table[a[j]]);
    printf("\n");
    }
    return 0;

}