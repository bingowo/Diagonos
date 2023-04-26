#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int gcd(int a,int b){
    return (a%b==0)?b:gcd(b,a%b);
}

int cmp(const void*a,const void*b){
    return *((int*)a)-*((int*)b);
}

int main(){
    int N,S;
    scanf("%d %d",&N,&S);
    int a[N];
    for(int n=0;n<N;n++)scanf("%d",&a[n]);
    qsort(a,N,sizeof(a[0]),cmp);
    int left=0,right=1;
    int high=a[0];
    int s=0;
    int wide=0;
    while(1){
        while(a[left]==a[right]&&right!=N)right++;
        
        wide+=right-left;
        if(S<wide)break;
        s=(S/wide)*wide;
        if(right!=N){
            if(s>wide*(a[right]-a[left]))s=wide*(a[right]-a[left]);
        }
        S-=s;
        high+=s/wide;
        if(S<wide&&high!=a[right])break;
        left=right;
    }
    
    if(high){
        printf("%d",high);
        if(S)printf("+");
    }
    if(S)printf("%d/%d",S/gcd(S,wide),wide/gcd(S, wide));
    printf("\n");
    return 0;
}
