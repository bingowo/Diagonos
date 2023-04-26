#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	long long int i,a[t];
	for(i=0;i<t;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<t;i++)
	{
		int j=0;
		long int s[61];
	while(a[i]!=0){
	s[j]=a[i]%2333;
	a[i]/=2333; 
    j++;
}
	for(int k=0;k<j;k++){
		printf("%d ",s[j-1-k]);
	}
	
	}}