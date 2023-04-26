#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
int T;
scanf("%d",&T);
for(int i;i<T;i++){
    int N,M,G;
    scanf("%d%d%d",&N,&M,&G);
    int fz[M];
    int m;
    for(int j=1;j<M+1;j++){
        scanf("%d",&m);
        fz[j]=m;
    }
    char s[12];
    int S,sum=0;
    for(int j=0;j<N;j++){
        scanf("%s",s);
        scanf("%d",&S);
        for(int k=9;k<S;k++){
            int a;
            scanf("%d",&a);
            sum=sum+fz[a];
        }
        if(sum>=G){

        }

    }
}
return 0;
}