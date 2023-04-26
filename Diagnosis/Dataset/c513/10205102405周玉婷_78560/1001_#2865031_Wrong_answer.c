#include <stdio.h>//进制转换 
int main()
{
	char arr[37]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',0};
	char arr1[500];
	int n,r,i=0,j=0;
	scanf("%d %d",&n,&r);
	do{
		arr1[i]=arr[n%r];
		i++;j++;
		n=n/r;
	} 
	while(n!=0); 
	for(j=j-1;j>=0;j--)
	printf("%c",arr1[j]);
	return 0;
}
