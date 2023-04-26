#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R,n,i=0,neg=0;
    int ans[33];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&n);
    getchar();
    while(n--){
        scanf("%d%d",&N,&R);
        getchar();
        if(N<0){
            N=N*(-1);
            neg=1;
        }
        do{
            ans[i++]=N%R;
            N=N/R;
        }while(N);
        if(neg==1){
            printf("-");
            neg=0;
        }
        for(int k=i-1;k>=0;k--)
            printf("%c",table[ans[i]]);
        printf('/n');
    }
    return 0;
}
