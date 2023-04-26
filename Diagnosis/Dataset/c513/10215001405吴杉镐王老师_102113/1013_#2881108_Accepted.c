#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[305];
long long gcd(long long x,long long y){
 if(x%y==0) return y;
 else return gcd(y,x%y);
}
int main() {
 scanf("%s",s);
 int i=0;
 long long sum1=0,sum2=0;
 for(;s[i]!='\0'&&s[i]!='.';i++){
  sum1*=3;
  if(s[i]=='2') sum1-=1;
  else sum1+=s[i]-'0';
 }
 long long res=1;
 if(s[i]=='.'){
  i++;
  for(;s[i]!='\0';i++){
   sum2*=3;
   if(s[i]=='2') sum2-=1;
   else sum2+=s[i]-'0';
   res*=3;
  }
  if(sum2<0 && sum1>0) sum2+=res,sum1--;
  else if(sum2>0 && sum1<0) sum1++,sum2=res-sum2;
 }
 if(res!=1){
  if(sum1!=0) printf("%lld %lld %lld\n",sum1,sum2/(gcd(res,sum2)),res/gcd(res,sum2));
  else {
   if(sum2>0) printf("%lld %lld\n",sum2/(gcd(res,sum2)),res/gcd(res,sum2));
   else printf("-%lld %lld\n",-sum2/(gcd(res,-sum2)),res/gcd(res,-sum2));
  }
 } 
 else printf("%lld\n",sum1);
 return 0;
}