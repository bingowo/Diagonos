#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long GCD(long long  x,long long  y){
	long long  r;
	if(x%y==0) return y;
	else { r=x%y;
		GCD(y,r);
	}
	return r;
}
 
long long  T(char x){long long zi;
	if(x=='1') zi=1;
		else if(x=='0') zi=0;
				else if(x=='2') zi=-1;
				return zi;}
int main()
{ char s[1000]={"\0"};
	char *p;
	int i,j;
	long long sum=0,zi=0,mu=1,r;
		scanf("%s",s);
		p=s;
		while(*p&&(*p!='.')){//处理整数部分 
			if(*p=='1') sum=sum*3+1;
			else if(*p=='0') sum=sum*3+0;
			else if(*p=='2') sum=sum*3-1;
			p++;
		}
	    p=p+1;	
		for(;*p;p++){ long long  t=T(*p);
			zi=zi*3+t;
			mu=mu*3;
		}
	    if(sum>0&&zi<0){
	    	sum=sum-1;
	    	zi=mu+zi;
		}
		else if(sum<0&&zi>0){
			sum=sum+1;
			zi=mu-zi;
			if(sum==0) zi=-zi;
		}
		r=GCD(abs(zi),abs(mu));
	    	zi=zi/r;mu=mu/r;
		if(zi==0)printf("%lld\n",sum);
		else {
			if(sum!=0) printf("%lld ",sum);
			printf("%lld %lld",zi,mu);
		}
		
   
 return 0;
}