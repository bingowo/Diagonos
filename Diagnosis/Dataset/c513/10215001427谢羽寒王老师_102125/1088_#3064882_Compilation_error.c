#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* stob(int m){
    int s[20],i;
    memset(s,0,sizeof(s));
    for(i=0;m>0;i++){
        s[0]=m%10;
        m=m/10;
    }
    return s;
}

int main()
{
    int m,n,T,i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d%d",&m,&n);
        printf("case #%d:",i);
        if(n>(m/2)) n=m-n;        //换成好算的
        int M[20],N[20];
        memset(M,0,sizeof(M));
        memset(N,0,sizeof(N));
        M=stob(m);
        N=stob(n);








    }