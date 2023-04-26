#include<stdio.h>
#include<stdlib.h>
int main(){
	char a[50],c;
	int i=-1,n[50],cntn=0,cnt=1,max;
	do{
		i++;
		scanf("%s",&a[i]);
	}
	while(a[i]!='\n');
	for(int j=0;j<i;j++){
		if(a[j]!=a[j+1])cnt++;
		else{
			n[cntn]=cnt;
			cntn++;
			cnt=1;
		}
	}
	max=n[0];
	for(int j=0;j<cntn;j++){
		if(n[j]<n[j+1])max=n[j+1];
	}
	printf("%d",max);
	return 0; 
} 