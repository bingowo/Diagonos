#include<stdio.h>
void change_dec_into_bin(const void* a,int dec)
{
	int* ax=(int*)a;
	int i=8;
	while(i--)
	{
		ax[i]=dec%2;
		dec/=2;
	}
}
int GCD(int a,int b){return a%b?GCD(a,a%b):b;}
int main()
{
	int n;scanf("%d",&n);
	char x=getchar();
	for(int i=0;i<n;i++)
	{
		char a;int d;
		int num1=0,total=0;
		while(a=getchar()!='\n')
		{
			d=a;int dec[8];
			change_dec_into_bin(dec,d);
			for(int i=0;i<8;i++)if(dec[i]==1)num1++;
			total+=8;
		}
		num1/=GCD(num1,total);
		total/=GCD(num1,total);
		printf("%d/%d\n",num1,total);
	}
	return 0;
}