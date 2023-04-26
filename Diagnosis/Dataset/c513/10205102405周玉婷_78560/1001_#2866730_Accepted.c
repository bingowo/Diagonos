#include <stdio.h>//进制转换 
int main()
{
	char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char temp[32];
	int t,n,r;
	scanf("%d",&t); 
	while(t>0)
	{
    int i=0,flag=0,j=0;
	scanf("%d %d",&n,&r);
	if(n<0) 
	{flag=1;n=-n;}
	do{
		temp[i]=table[n%r];
		i++;j++;
		n=n/r;
	} 
	while(n); 
	t--;
	if(flag) printf("-");
	for(j=j-1;j>=0;j--)
	printf("%c",temp[j]);
	printf("\n");
	}
	
	return 0;
}
