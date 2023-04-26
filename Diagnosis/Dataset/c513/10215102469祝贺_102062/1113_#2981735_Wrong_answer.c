#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    unsigned long long tab[n+1];

    if(n>=2)tab[2]=1;
    if(n>=3)tab[3]=1;
    if(n>=4)tab[4]=2;

    for(int i=5;i<=k;i++){
        tab[i]=2*tab[i-1];
    }


    if(n>=5  && n>k){
        for(int i=k+1;i<=n;i++){
            tab[i]=tab[i-1]*2;
            if(i-k-1>1)tab[i]-=tab[i-k-1];
        }
    }

    if(n==1)printf("0");
    else printf("%llu",tab[n]);
    return 0;
}
