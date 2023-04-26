#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int GCD (int m,int n) {
if (n==0)
return m;
else return GCD(n,m%n);
}

int main () {
char s[50];
scanf ("%s", s);
unsigned int p=0;

long long ansA=0;

long long ansB=0, ansC=1;

for (;p<strlen(s);p++) {//整数部分

   if (s[p]=='.') break;

   ansA = ansA *3;

   if (s[p]=='1') ansA += 1;

   if (s[p]=='2') ansA -= 1;

}

p++;

for (;p<strlen(s);p++) { //小数部分

    ansB =ansB * 3;      //分子

    if (s[p]=='2') ansB -= 1;

    if (s[p]=='1') ansB += 1;

    ansC = ansC * 3;      //分母

}
if (ansA>0&&ansB<0) {
    ansA--;
    ansB=ansC+ansB;
}
else if(ansA<0&&ansB>0) {
    ansA++;
    ansB=ansC-ansB;
}
else if (ansA==0) {
    ansB=-ansB;
}
long long t=GCD(llabs(ansB),llabs(ansC));







  if (ansB==0) printf("%lld\n",ansA);

 else

  {   if (ansA!=0) printf("%lld ",ansA);

         printf("%lld %lld\n",ansB/t,ansC/t);

   }
   return 0;
}
