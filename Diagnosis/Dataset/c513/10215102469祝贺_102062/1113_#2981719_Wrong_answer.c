#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(){
    int k,n;
    scanf("%d%d",&k,&n);
    long long tab[n+1];
    tab[0]=0;
    tab[1]=0;
    if(n>=2)tab[2]=1;
    if(n>=3)tab[3]=1;
    for(int i=4;i<=k;i++){
        tab[i]=2*tab[i-1];
    }
    if(k+1>=4){
        tab[k+1]=0;
        for(int i=1;i<=k;i++)tab[k+1]+=tab[i];
    }

    for(int i=k+2;i<=n;i++){
        tab[i]=tab[i-1]*2-tab[i-k-1];
    }
    printf("%llu",tab[n]);
    return 0;
}
