#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R,n,temp,i=0,neg=0;
    int ans[33];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&N,&R);
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
        for(i=i-1;i>=0;i--){
            temp=ans[i];
            printf("%c",table[temp]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
