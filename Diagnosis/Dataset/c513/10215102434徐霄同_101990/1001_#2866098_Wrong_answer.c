#include <stdio.h>

int main()
{
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int t,n,r,i,r0;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&n,&r);
        if(n<0){
            printf("-");
            n=n*(-1);
        }
        for(r0=1;r0*r<=n;r0=r0*r);
        while(r0>0){
            printf("%c",table[n/r0]);
            n=n%r0;
            r0=r0/r;
        }
        printf("\n");
    }
    return 0; 
}
