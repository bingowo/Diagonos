#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define inf 1005

long long f(long long a,long long b){
    if(a<b) return b-a;
    else return a-b;
}

int main(){

    int d,n;scanf("%d%d",&d,&n);
    double maxt=0;
    for(int i=0;i<n;i++){
        int k,v;scanf("%d%d",&k,&v);
        if((d-k)*1.0/v>maxt) maxt=(d-k)*1.0/v;
    }

    printf("%.6f",d/maxt);
    return 0;
}
