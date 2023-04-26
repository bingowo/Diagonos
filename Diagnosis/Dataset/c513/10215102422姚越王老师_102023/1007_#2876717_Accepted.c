#include<stdio.h>
#include<string.h>
#include<math.h>
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
int findlongest(const void* a)
{
	int *ax=(int*)a;
	int length=1,max=1;
	int i=0;
	while(!ax[++i]);
	for(i;i<31;i++)
	{
		if(ax[i]!=ax[i+1])length++;
		else length=1;
		if(length>max)max=length;
	}
	return max;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int cnt=0;cnt<n;cnt++)
	{
		int store[32];
		int dec;scanf("%d",&dec);
		change_dec_into_bin(store,dec);
		printf("case #%d:\n%d\n",cnt,findlongest(store));
	}
	return 0;
	
}