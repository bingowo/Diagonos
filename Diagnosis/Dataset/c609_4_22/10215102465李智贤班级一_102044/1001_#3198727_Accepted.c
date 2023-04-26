#include <stdio.h>
#include <stdlib.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    int T,N,R,a[33],j,k;
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&T);
    for(int k=0;k<T;k++){

        scanf("%d%d",&N,&R);
        int flag=0;
        if(N<0){
            N=-N;
            flag=1;
        }
        int i=0;
        do{
            a[i]=N%R;
            i++;
            N=N/R;
        }
        while(N);

        if(flag==1) printf("-");
        for(j=i-1;j>=0;j--) printf("%c",table[a[j]]);
        printf("\n");
    }
    return 0;
}

