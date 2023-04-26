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
 
int main()
{ char s[1000];
	int i,j;
	long long sum=0,zi=0,mu=1,r;
		scanf("%s",s);
		unsigned int l=strlen(s);
		unsigned int p=0;
		while(p<l){//处理整数部分 
			if(s[p]=='.') break;
			if(s[p]=='1') sum=sum*3+1;
			else if(s[p]=='0') sum=sum*3+0;
			else if(s[p]=='2') sum=sum*3-1;
			p++;
		}
	    p=p+1;	
		for(;p<l;p++){ 
			zi=zi*3;
			if(s[p]=='1') zi+=1;
			if(s[p]=='2') zi-=1;
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