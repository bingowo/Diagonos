#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T;
    int N;
    int R;
    int a,b,i=0;
    char m[32];
    scanf("%d",&T);
    while(T>0){
            scanf("%d%d",&N,&R);
    do{
        a=N/R;
        b=N%R;
        if(b<10)
            m[i++]=b+'0';
        else
            m[i++]=b-10+'A';
        N=a;}while(N!=0);

        while(i>=0){
            printf("%c",m[--i]);

        }
        i=0;
        T--;}
return 0;
}
