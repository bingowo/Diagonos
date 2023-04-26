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
		
		x=s[0];
		a[x]=1;
		if(a[s[1]]==-1){
			x=s[1];
			a[x]=0;	
		}
		
		j=2;
		jz=2;
		//每次读入字符串进行一次运算把答案存储在result中 
		
		while((s[2]!='\0')&&(s[j]!='\0')){
			if(a[s[j]]==-1){
				a[s[j]]=j;
				jz++;
			}
			j++;
			
		}//记录每个字符的含义 
		
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