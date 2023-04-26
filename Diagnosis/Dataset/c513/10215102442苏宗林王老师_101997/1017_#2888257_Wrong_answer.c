#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

int main(){
	long long an,re[10000];
    int flag=0,i,n,temp=0,a[128];
	char s[10000];
	for(int ij=0;ij<10000;ij++)re[ij]=1;
	a['I']=1;
	a['V']=5;
	a['X']=10;
	a['L']=50;
	a['C']=100;
	a['D']=500;
	a['M']=1000;
	scanf("%s",&s);
	n=strlen(s);
	for(i=0;i<n;i++){
		if(s[i]!='('){
			if(flag){
				for(int qw=0;qw<flag;qw++){
					re[temp]*=1000;
				}
			}
			re[temp]*=a[s[i]];
			//printf("%d temp %d\n",re[temp],temp);
			if((temp>0)&&(re[temp]>re[temp-1])){
				re[temp-1]*=-1;
				//printf("%d temp %d\n",re[temp-1],temp-1);	
			}
			temp++;
		}
		else if(s[i]==')'){
			flag--;
			
			
		}
		else{
			
			flag++;
			temp++;
		}
		
		
	}
	an=0;
		for(int k=0;k<temp;k++){
			an+=re[k];
			//printf("%lld \n",an);
		}
		printf("%lld",an);	
	return 0;
}