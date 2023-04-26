#include<stdio.h>
int main()
{
	int t,k,i;
	scanf("%d",&t);
	long long int a[t];
	for(i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<t;i++){
		int j=0;
		int s[61];
		while(a[i]!=0){
			s[j]=a[i]%2333;
			a[i]/=2333; 
		    j++;
		}
		for(k=0;k<j-1;k++){
			printf("%d ",s[j-1-k]);
		}
		printf("%d\n",s[0]);
	}
}	