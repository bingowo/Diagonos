#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int code[6000]={0,0,0,1},sp=4;
void itob(long long n,int bits)
{
	int p=sp+bits-1;
	while(p>=sp)
	{
		code[p--]=n%2;
		n/=2;
	}
	sp+=bits;
}
int main()
{
	char num[500];scanf("%s",num);
	itob(strlen(num),10);
	int i=0,len=strlen(num);
	for(;i<=len-3;i+=3)
	{
		int n=(num[i]-'0')*100+(num[i+1]-'0')*10+num[i+2]-'0';
		itob(n,10);
	}
	if(len-i==2)
	{
		int n=(num[i]-'0')*10+(num[i+1]-'0');
		itob(n,7);
	}
	else
		itob(num[i]-'0',4);
	
	for(int i=0;i<sp;i++)printf("%d",code[i]);
	printf("\n");
	
	return 0;
}
