#include<stdio.h>
int main()

{
	int t,j,i,a[128],digit,N;
	char s[61];
	long long int ans;
	
	scanf("%d",&t);
	for(i=0;i<t;i++){
	    digit=0;
	    N=1;
	    ans=0;
		scanf("%s",&s);
		for(j=0;j<128;j++)
		a[j]=-1;
		char *p=s;
		a[*p]=1;
		while(*++p){
		
		if(a[*p]==-1){
			a[*p]=digit;
			digit=digit?digit+1:2;
			N+=1;
		    }
			if(N<2)
			N=2; 
			
		}
		p=s;
		while(*p){
			ans=ans*N+a[*p++];
		}
		printf("case #%d:\n",i);
		printf("%d\n",ans);
		
		
	}
}