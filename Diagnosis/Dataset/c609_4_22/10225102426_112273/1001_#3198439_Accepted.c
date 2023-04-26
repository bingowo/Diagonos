#include<stdio.h>

int main()
{
    int i=0,j=0,T=0,N=0,R=0,M=0;
    char a[100];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d",&N,&R);
        if(N<0){
            printf("-");
            N=-1*N;
        }
        for(N=N;N>0;){
            M=N%R;
            N=N/R;
            if(M<10){
                a[j]=M+'0';
            }
            else{
                a[j]=M-10+'A';
            }
            j++;
        }
        for(j=j;j>0;j--){
            printf("%c",a[j-1]);
        }
        printf("\n");
    }
    return 0;
}
