#include<stdio.h>
#include<stdlib.h>
int S[51]={0};
long long solve(int n){
    if(n==0)return 1;
    else if(n<0)return 0;
    if(S[n])return S[n]; 
    else if(!S[n]){
        S[n]=solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4);
    }
    return S[n];
}
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
int num;
scanf("%d",&num);
long long ans=solve(num);
printf("case #%d:\n",i);
printf("%lld\n",ans);
}
return 0;
}
