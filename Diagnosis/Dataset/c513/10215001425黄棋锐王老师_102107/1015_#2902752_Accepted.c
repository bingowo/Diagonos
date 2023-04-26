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
//	int fen(int*p,int k){
//		int j=0,pro=1;
//		for(j=0;j<k;j++) pro*=p[j];
//		return pro;
//	}
void Add(int a[],int b[],int c[]){
	int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
		53,59,61,67,71,73,79,83,89,91,97};
		int i,j,k;
		for(j=26;j>=0&&a[j]==0;j--);
		for(k=26;k>=0&&b[k]==0;k--);
		for(i=0;i<=j||i<=k;i++){
			c[i]=a[i]+b[i]+c[i];
			if(c[i]>=prime[i]){
			c[i+1]+=1;
			c[i]-=prime[i];
							  }
									 }
							}
int main(){
	int T,i;
	scanf("%d\n",&T);
		for(i=0;i<T;i++){
			char s[100];
			int a[27]={0};
			int b[27]={0};
			int c[27]={0};
			scanf("%s",s);
			Readnumber(s,a);
			scanf("%s",s);
			Readnumber(s,b);
			Add(a,b,c);
			printf("case #%d:\n",i);
			int j;
			for(j=26;j>=0&&c[j]==0;j--);
			for(;j>0;j--) printf("%d,",c[j]);
			printf("%d\n",c[0]);
		}
	
		return 0;
}