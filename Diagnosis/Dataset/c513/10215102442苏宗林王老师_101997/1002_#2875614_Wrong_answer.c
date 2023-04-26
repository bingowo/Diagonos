#include<stdio.h>
int main(){
	int n,i,j,jz,x;
	int a[128];
	scanf("%d",&n);
	int result[20]; 
	char s[61];
	long long answer,weight;
	for(int k=0;k<128;k++){
		a[k]=-1;
	}
	
	for(i=0;i<n;i++){
		scanf("%s",&s);
		
		
		
		
		//每次读入字符串进行一次运算把答案存储在result中 
		j=0;
		jz=0;
		while(s[j]!='\0'){
			if(a[s[j]]==-1){
				if(jz==0){
					a[s[j]]=1;
				}
				else if(jz==1){
					a[s[j]]=0;
				}
				else{
					a[s[j]]=jz;	
				}
				
				jz++;
			}
			j++;
			
		}//记录每个字符的含义 
		if(jz==1){
			jz=2;
		}
		x=s[j-1];
		answer=a[s[j-1]];
		weight=jz;
		for(int k=0;k<j-1;k++){
			answer+=(weight*a[s[j-2-k]]);
			weight*=jz;
			
		}
		result[i]=answer;
		if(s[1]=='\0'){
			result[i]=1;
		}
	}
	
	for(int q=0;q<n;q++){
		printf("case #%d:\n%lld\n",q,result[q]);
	}
	
	return 0;
}