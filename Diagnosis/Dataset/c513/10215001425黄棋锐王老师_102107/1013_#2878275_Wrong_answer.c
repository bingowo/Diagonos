#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int GCD(int x,int y){
	int r;
	if(x%y==0) return y;
	else { r=x%y;
		GCD(y,r);
	}
	return r;
}
int main()
{ char s[1000];
	char *p;
	int i,j,T,sum=0,zi=1,mu=1,r;
		scanf("%s",s);
		p=s;
		while(*p&&(*p!='.')){//处理整数部分 
			if(*p=='1') sum=sum*3+1;
			else if(*p=='0') sum=sum*3+0;
			else if(*p=='2') sum=sum*3-1;
			p++;
		}
	    if(*p=='.'){while(*p) p++;
	    	while(*--p!='.'){if(*p=='1') zi=1*mu+zi;
			else if(*p=='0') zi=0*mu+zi;
			else if(*p=='2') zi=(-1)*mu+zi;
			mu=mu*3;
			}
	    	r=GCD(zi,mu);
	    	zi=zi/r;mu=mu/r;
	    	if((sum*zi)<0) {int sign =sum/abs(sum);
			sum=sign*(abs(sum)-1);
			zi=1*mu-zi;
			r=GCD(zi,mu);
	    	zi=zi/r;mu=mu/r;
			}
			if(sum!=0)printf("%d %d %d",sum,zi,mu);
			else printf("%d %d",zi,mu);
		}
		else printf("%d",sum);
	
   
 return 0;
}