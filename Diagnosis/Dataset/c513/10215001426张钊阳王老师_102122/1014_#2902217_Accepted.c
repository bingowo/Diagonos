#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long  GCD(long long x,long long y){
 long long r;
 if(x%y==0) return y;
 else {
  r=x%y;
  GCD(y,r);
 }
} 
int main(){
 long long A,B,t;
 scanf("%lld %lld",&A,&B);
 long long  In=A/B;//整数部分 
 long long N=A-In*B; //分子部分
 long long zi,mu;
 long long r=GCD(N,B);
 zi=N/r,mu=B/r;
 int i=0,j=0;//i为整数参数,j为小数参数 
    long long Z[100]={0};//三进制整数部分 
 long long M[100]={0};//三进制小数部分 
 do{ //整数部分 ，必须至少进行一次保证有一位可以用来进1 
  Z[i++]=In%3;
  In=In/3;
 } while(In!=0);
  int d=i,k;
  i=i-1;
 for(k=0;k<i;k++,i--) t=Z[k],Z[k]=Z[i],Z[i]=t;
 while(mu!=1){//小数部分 
  mu=mu/3;
  M[j++]=zi/mu;
  zi=zi%mu;
 } 
  int x=j;
  for(j=x-1;j>0;j--) {
   M[j]+=1;
   if(M[j]>=3){
    M[j-1]+=1;
    M[j]=M[j]-3;}
   } M[0]+=1;
   if(M[0]>=3) M[0]=M[0]-3,Z[d-1]+=1;
  for(i=d-1;i>0;i--) {
   Z[i]+=1;
   if(Z[i]>=3){
    Z[i-1]+=1;
    Z[i]=Z[i]-3;
   }
  }
  Z[0]+=1;
   if(Z[0]>=3){
    for(i=d;i>1;i--) Z[i]=Z[i-1];
    Z[1]=Z[0]-3,Z[0]=2;
    d=d+1;
   }
   for(j=0;j<x;j++){
    M[j]-=1;
    if(M[j]==-1) M[j]=2;
   }
   for(i=0;i<d;i++){
    Z[i]-=1;
    if(Z[i]==-1) Z[i]=2;
   }
   for(i=0;Z[i]==0&&i<d;i++);
   for(j=x-1;M[j]==0&&j>=0;j--);
   if(i==d) printf("0");
   else if(i<d){
    for(;i<d;i++) printf("%lld",Z[i]);
   }
   if(j>=0){
    printf(".");
    for(k=0;k<=j;k++) printf("%lld",M[k]);
   }
  return 0;
}
