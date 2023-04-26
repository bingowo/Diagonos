#include <stdio.h>


int main()
{
	
	int num[21];
	num[1]=2;
	num[2]=4;
	num[3]=7;
	for (int i=4;i<21;i++){
		num[i]=2*num[i-1]-num[i-2]+num[i-3];
	}
	int n;
	scanf("%d",&n);
	while(n!=-1){
		printf("%d\n",num[n]);
		scanf("%d",&n);
	}
	return 0;
}