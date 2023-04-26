#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
long long g(long long a,long long b){//b>a
	long long c=0;
	while((c=b%a)!=0){
		b=a;a=c;
	}
	return a;
}
int main(){
	long long n,s;scanf("%lld%lld",&n,&s);
	int valley[n+2],p1=0,p2=0;
	valley[0]=2000;valley[n+1]=2000;
	for(int i=1;i<n+1;i++){
		scanf("%d",&valley[i]);
		if(i>0 && valley[i]<valley[i-1]){
			p1=i;p2=i+1;
		}
	}
	while(valley[p2]==valley[p1])p2++;
	p2-=1;
	int ans=valley[p1];
	int lower=valley[p2+1]<valley[p1-1]?p2+1:p1-1;
	int hole=(p2-p1+1)*(valley[lower]-valley[p1]);
	while(s-hole>=0){
		s-=hole;ans=valley[lower];
	if(lower==p2+1){
		p2++;
			while(valley[p2+1]==valley[p2+2])p2++;
			if(valley[p1-1]==valley[lower]){
				while(valley[p1-2]==valley[p1-1])p1--;
			}
		}
	else if(lower==p1-1){
		p1--;
			while(valley[p1-1]==valley[p1-2])p1--;
			if(valley[p2+1]==valley[lower]){
				while(valley[p2+2]==valley[p2+1])p2++;
			}
		}
 		lower=valley[p2+1]<valley[p1-1]?p2+1:p1-1;
		hole=(p2-p1+1)*(valley[lower]-ans);
	}
	ans+=s/(p2-p1+1);
	s=s%(p2-p1+1);
	if(s>0){
		long long a=s,b=p2-p1+1,t=g(a,b);
		printf("%lld+%lld/%lld",ans,a/t,b/t);
	}
	else{
		printf("%lld",ans);
	}
}