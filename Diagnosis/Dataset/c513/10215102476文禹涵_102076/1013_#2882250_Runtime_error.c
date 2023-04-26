#include <stdio.h>
#include <string.h>
#include <math.h>

int gcd(int m,int n)
{    
    int t,r;    
    if (m<n)//为了确保是大数除小数    
    {        
        t=m;        
        m=n;       
        n=t;    
    }    
 
    while((m%n)!=0)//辗转相除    
    {        
        r=m%n;        
        m=n;        
        n=r;    
    }   
 
    return n;
}

int main() 
{     
    char s[10000] = {0};
	unsigned int p = 0;
    long long ansA = 0;
    long long ansB = 0,ansC = 1;
    for (;p<strlen(s);p++){
        if (s[p] == '.') break;
		ansA = ansA * 3;
		if (s[p] == '1') ansA += 1;
		if (s[p] == '2') ansA -= 1; 
    }
    p++;
    for (;p<strlen(s);p++){
    	ansB = ansB * 3;
    	if (s[p] == '2') ansB -= 1;
    	if (s[p] == '1') ansB += 1;
    	ansC = ansC * 3;
	}
	if (ansA > 0 && ansB < 0){
	    ansA--;
	    ansB = ansC + ansB;}
	if (ansA < 0 && ansB > 0){ 
	    ansA++;
	    ansB = ansC - ansB;}
	if ( ansA == 0) ansB = -ansB;
	long long t = gcd(abs(ansB),abs(ansC));
	if (ansB==0) printf("%lld\n",ansA);
    else{
	if (ansA!=0) printf("%lld ",ansA);
    printf("%lld %lld\n",ansB/t,ansC/t);
    }
}
