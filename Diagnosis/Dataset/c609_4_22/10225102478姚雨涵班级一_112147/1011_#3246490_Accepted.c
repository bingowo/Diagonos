#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(long long int a, long long int b) {
 long long int max = a;
 long long int min = b;
 if(max<0)
    max = -max;
 if(min<0)
    min = -min;
 long long int c = max % min;
 if (c == 0)
  return min;
 max = min;
 min = c;
 GCD(max, min);
}

int main() {
 unsigned int p = 0;
 char s[50];
 scanf("%s",&s);
 long long int ansA = 0,ansB = 0,ansC = 1;
 for(;p<strlen(s);p++){
    if(s[p] == '.')
        break;
    ansA = ansA *3;
    if(s[p] == '1')
        ansA += 1;
    if(s[p] == '2')
        ansA -= 1;
 }
 p++;
 for(;p<strlen(s);p++){
    ansC = ansC * 3;
    ansB = ansB *3;
    if(s[p] == '1')
        ansB += 1;
    if(s[p] == '2')
        ansB -= 1;
 }
 if(ansA > 0&&ansB < 0){
    ansA--;
    ansB = ansB + ansC;
 }
 if(ansA<0&&ansB>0){
    ansA++;
    ansB = ansC - ansB;
    if(ansA == 0)
        ansB = -ansB;
 }
long long int temp = GCD(ansB,ansC);
if (ansB==0)
    printf("%lld\n",ansA);
 else{
    if (ansA!=0)
        printf("%lld ",ansA);
    printf("%lld %lld\n",ansB/temp,ansC/temp);
   }

 return 0;
}
