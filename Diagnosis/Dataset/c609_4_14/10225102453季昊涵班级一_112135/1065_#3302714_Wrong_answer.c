#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	int T;
	scanf("%d",&T);
	int k=0;
	while(T--){
		char in[11];
		char st[100];
		double db[3];
		int s=0;
		int d=0;
		while((scanf("%s",&in))!=EOF){
			if(isdigit(in[0])){
				db[d++]=atof(in);
			}
			else
			st[s++]=in[0];	
			if(d==2){
				double temp1=db[0];
				double temp2=db[1];
				d=0;
				if(st[s--]=='+')
				db[d++]=temp1+temp2;
				else if(st[s--]=='*')
				db[d++]=temp1*temp2;
				else if(st[s--]=='/')
				db[d++]=temp1/temp2;
				else if(st[s--]=='-')
				db[d++]=temp1-temp2;
			}
		}
		printf("case #%d:\n",k++);
		printf("%.6lf\n",db[0]);
		
	}	
	
	return 0;
}