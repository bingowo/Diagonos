#include <stdio.h>
#include <string.h>
#include <math.h>
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
int main()
{char s[30];
scanf ("%s",&s);
unsigned int p=0;
long long ansA=0;
long long ansB=0, ansC=1;
long long t=gcd(abs(ansB),abs(ansC));
for (;p<strlen(s);p++) 
{
	if (s[p]=='.') break;
	ansA = ansA *3;
	if (s[p]=='1') ansA += 1;
	if (s[p]=='2') ansA -= 1;
}
p++;
for (;p<strlen(s);p++) { 
	ansB =ansB * 3; 
	if (s[p]=='2') ansB -= 1;
	if (s[p]=='1') ansB += 1;
	ansC = ansC * 3; 
}
if (ansB<0) ansB=ansC+ansB; 
if (ansB==0) printf("%lld\n",ansA);
else
{ if (ansA!=0) printf("%lld ",ansA);
printf("%lld %lld\n",ansB/t,ansC/t);
}
}