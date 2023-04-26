#include<stdio.h>
int main()
{
    int N=0,R=0,M=0;
    int T=0,count=0;
    char a[100];
    scanf("%d",&T);
    for(T=T;T>0;T--){
        scanf("%d %d",&N,R);
        if(N<0){
            printf("-");
        }
        while(N!=0){
            M=N%R;
            N=N/R;
            if(M<10){
                a[count]=M;
            }
            else{
                a[count]=(M-10)+'A';
            }
            count++;
        }
        for(count=--count;count>=0;count--){
            printf("%c\n",a[count]);
        }
    }
    return 0;
}
