#include<stdio.h>
int main(){
    int N,R,T,a,b,i=0;
    char m[32];
    scanf("%d",&T);
    while(T-->0){
        do{
        a = N/R;
        b = N%R;
        if(b<10)m[i++]=b+'0';
        else
            m[i++]=b-10+'A';
    };
    while(a!=0);
    for(i--;i>=0;i--)printf("%c",m[i]);
    i=0;
    }
    return 0;
}