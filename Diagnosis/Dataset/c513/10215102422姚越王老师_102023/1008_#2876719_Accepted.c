#include<stdio.h>
void change_dec_into_bin(const void* a,int dec)
{
	int* ax=(int*)a;
	int i=32;
	while(i--)
	{
		ax[i]=dec%2;
		dec/=2;
	}
}
int main()
{
	int n;scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
		int a,b;scanf("%d%d",&a,&b);
		int a_b[32],b_b[32];
		change_dec_into_bin(a_b,a);
		change_dec_into_bin(b_b,b);
		int cnt=0;
		for(int i=0;i<32;i++)
		{
			if(a_b[i]!=b_b[i])cnt++;
		}
		printf("%d\n",cnt);
			
	}
	return 0;	
}