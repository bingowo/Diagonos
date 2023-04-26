#include<stdio.h>
int main()
{
    int N,R,M=0;
    int T=0;
    char M2='A';
    scanf("%d",&T);
    if(T<0){
        T=-1*T;
        printf("-1");
    }
    for(T=T;T>0;T--){
        scanf("%d %d",&N,R);
        while(N!=0){
            M=N%R;
            N=N/R;
            if(M<10){
                printf("%d",M);
            }
            else{
                M2=M2+(M-10);
                printf("%c",M2);
            }
        }
        printf("\n");
    }
    return 0;
}
