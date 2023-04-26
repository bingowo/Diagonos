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
int ci(int x,int y){
	int i;
	for(i=0;i<y;i++)  x=x*3;
	return x;
}
int T(char x){int zi;
	if(x=='1') zi=1;
		else if(x=='0') zi=0;
				else if(x=='2') zi=-1;
				return zi;}
int main()
{ char s[1000];
	char *p;
	int i,j,sum=0,zi=0,mu=0,r;
		scanf("%s",s);
		p=s;
		while(*p&&(*p!='.')){//处理整数部分 
			if(*p=='1') sum=sum*3+1;
			else if(*p=='0') sum=sum*3+0;
			else if(*p=='2') sum=sum*3-1;
			p++;
		}
	    if(*p=='.'){  int l=0; 
	    	p=p+1;
		  l=strlen(p);
//	    	for(i=0;*(--p)!='.';i++){ 
//	    	if(i==0){if(*p=='1') zi=1;
//			else if(*p=='0') zi=0;
//			else if(*p=='2') zi=-1;mu=3;
//			}
//			else{
//			if(*p=='1') zi=1*mu+zi;
//			else if(*p=='0') zi=0*mu+zi;
//			else if(*p=='2') zi=(-1)*mu+zi;mu=mu*3;
//			}
//			}
		 mu=ci(1,l);
		for(i=0;i<l;i++,p++){ int t=T(*p);
			zi=zi+ci(t,l-1-i);
		}
	    	r=abs(GCD(zi,mu));
	    	zi=zi/r;mu=mu/r;
	    	if(sum!=0&&(sum*zi)<0) {int sign =sum/abs(sum);
			sum=sign*(abs(sum)-1);
			sign=zi/abs(zi);
			zi=sign*(1*mu-zi);
			r=abs(GCD(zi,mu));
	    	zi=zi/r;mu=mu/r;
			}
			if(sum!=0&&zi!=0)printf("%d %d %d",sum,zi,mu);
			else if(sum==0&&zi!=0)printf("%d %d",zi,mu);
			else if(sum==0&&zi==0) printf("0");
			else if(sum!=0&&zi==0) printf("%d",sum);
		}
		else printf("%d",sum);
	
   
 return 0;
}