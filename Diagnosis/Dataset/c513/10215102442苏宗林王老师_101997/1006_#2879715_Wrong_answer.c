#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
int main(){

	int i,n,re,weight,j,a[128];
	a['1']=1;
	a['-']=-1;
	a['0']=0;
	char s[10000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s);
		re=0;
		weight=1; 
		for(j=1;j<=strlen(s);j++){
			re+=(weight*a[s[strlen(s)-j]]);
			weight*=3;
		}
		printf("case #%d:\n%d",i,re);
	}
	return 0;
}