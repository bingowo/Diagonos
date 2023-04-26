#include<stdio.h>
#include<stdlib.h>

struct group{
    long long m;int l;
};

int num(long long m){
    while(m>=10||m<=-10){
        m/=10;
    }
    int n=m;
    return n;
}
int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        int n;
        scanf("%d",&n);
        struct group g[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&g[i].m);
        }
        a++;
    }
}