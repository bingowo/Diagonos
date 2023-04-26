#include<stdio.h>
int main()
{
	int t,k,i;scanf("%d",&t);
	long long int a;
	for(i=0;i<t;i++){
		scanf("%lld",&a);
		int j=0,s[61];
		while(a!=0){
			s[j]=a%2333;
			a/=2333; 
		    j++;
		}
		for(k=j-1;k>=0;k--){printf("%d ",s[k]);}
		printf("\n");
	}
}	