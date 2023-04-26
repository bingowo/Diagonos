#include<stdio.h>
#include<stdlib.h>
int trans(long long n){
   if(n==0)return 0;
   long long a=n%-2;
   long long b=n/-2;
   if(a<0){a-=-2;b+=1;}
   trans(b);
   printf("%lld",a);
}
int main(){
  long long num;
  scanf("%lld",&num);
  if(num==0)printf("0");
  trans(num);
  return 0;
}