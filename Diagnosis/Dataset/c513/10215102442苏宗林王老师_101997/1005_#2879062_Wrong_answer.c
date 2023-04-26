#include<stdio.h>
#include<stdlib.h> 

int main(){

	int i,n,k,flag;
	float weight,re;
	char s[51];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		
		re=0.0;
		weight=1.0/8;
		
		scanf("%s",&s);
		k=0;
		flag=0;
		
		while(s[k]!='\0'){
			
			if(k>1){
				re+=(weight*(s[k]-'0'));
				
				weight/=8;
			}
			if(s[k]=='.'){
				flag=1;
				//printf("ok");
			}
			k++;
		}
		printf("case #%d:\n%f\n",i,re);
	}
	return 0;
}