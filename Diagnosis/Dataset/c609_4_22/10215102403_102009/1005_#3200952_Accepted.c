#include<stdio.h>
int main(){
	int t,i=0,j=0; 
	scanf("%d\n",&t);
	while(j<t){
		char a[20];
		scanf("%s\n",a);
		int sum=0;
		while(a[i]){
			if(a[i]=='1') sum+=1;
			else if(a[i]=='-') sum-=1; 
			sum*=3; i++;
		}
		sum/=3;
		printf("case #%d:\n%d\n",j,sum);
		j++; i=0; 
	}
	return 0;
} 