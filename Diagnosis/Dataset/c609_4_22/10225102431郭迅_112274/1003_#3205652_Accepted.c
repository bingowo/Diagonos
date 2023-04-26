#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	long long int i,a[t];
	for(i=0;i<t;i++){
		scanf("%lld",&a[i]);
	}
	for(i=0;i<t;i++)
	{
		int j=0;
		long long int s[61];
	if(a[i]==0){printf("%lld\n",a[i]);}
	else{
	while(a[i]!=0){
	s[j]=a[i]%2333;
	a[i]/=2333; 
    j++;
}
	for(int k=0;k<j-1;k++){
		printf("%lld ",s[j-1-k]);
	}
	printf("%lld\n",s[0]);
	}}	
}