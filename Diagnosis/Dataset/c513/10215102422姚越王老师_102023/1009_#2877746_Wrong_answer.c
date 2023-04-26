#include<stdio.h>
#include<string.h>
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
int GCD(int a,int b){return a%b?GCD(b,a%b):b;}
int main()
{
	int n;scanf("%d",&n);
	char x=getchar();
	for(int i=0;i<n;i++)
	{
		char s[1005];gets(s); 
		int num1=0,total=0;
		for(int j=0;j<strlen(s);j++)
		{
			int dec[8];
			change_dec_into_bin(dec,(unsigned int)s[j]);
			for(int i=0;i<8;i++)if(dec[i]==1)num1++;
			total+=8;
		}
		int c=GCD(num1,total);
		num1/=c;
		total/=c;
		printf("%d/%d\n",num1,total);
	}
	return 0;
}