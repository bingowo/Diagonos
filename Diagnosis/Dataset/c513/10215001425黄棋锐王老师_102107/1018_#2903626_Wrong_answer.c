#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void Readnumber(char*s,int* a){
	int j=0,l=0,t;
	int ss[100]={0};
	while(j<strlen(s)) { t=0;
		for(;s[j]!=','&&j<strlen(s);j++) t=t*10+s[j]-'0';
		ss[l++]=t;
		j++;
	} 
	for(j=0;j<l;j++){
		a[l-j-1]=ss[j];
	}
}
	unsigned long long  fen(int*p,int k){
		int j=0;
		unsigned long long pro=1;
		for(j=0;j<k;j++) pro*=p[j];
		return pro;
	}
unsigned long long Change(int a[]){
	int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
		53,59,61,67,71,73,79,83,89,91,97};
		int i,j,k;
	unsigned long long ans=0,flag=1;
		for(j=26;j>=0&&a[j]==0;j--);//00001203的1的位置 
		for(i=0;i<=j;i++){
			flag=i>0?fen(prime,i):1;
			ans+=a[i]*flag;
			  			    }
		 return ans;
	}
int main(){
		char s[100];
		int a[27]={0};
		unsigned long long ans=0;
			scanf("%s",s);
			Readnumber(s,a);
			ans=Change(a);
			printf("%ulld",ans);
	
		return 0;
}