#include <stdio.h>
void add(int *s,int *a)
{

	int i,carry=0;
	
	for(i=30;i>=0;i--)
	{
		s[i]=s[i]+a[i]+carry;
		carry=s[i]/10;
		s[i]=s[i]%10;
	}
	
}
void minu(int *s,int *b)
{
	int carry=0;
	int i=30;
	for(i=30;i>=0;i--)
	{
		s[i]-=carry;
		if(s[i]<b[i])
		{
			carry=1;
			s[i]=s[i]+10;
			s[i]=s[i]-b[i];
			
		}
		else
		{
			s[i]=s[i]-b[i];
			carry=0;
		}
	}
	
}
int main()
{
	int k,n;
	scanf("%d %d",&k,&n);
	int a[101]={0};
	a[0]=0;a[1]=1;
	int i=2;
	int sum=0;
	for(i;i<k;i++)
	{
		//printf("h\n");
		sum+=a[i-1];
		a[i]=sum;
	}
	if(n<=k)
	{
		printf("%d\n",a[n-1]);
		goto end;
	}
	i--;

	int s[31]={0},j;
	int fi[101][31]={0};
	for(j=0;j<k;j++)
	{
		int d=0;
		for(d=30;d>=0;d--)
		{
			fi[j][d]=a[j]%10;
			a[j]/=10;
		}
	}
	//printf("%d\n",sum);
	for(j=30;j>=0;j--)
	{
		s[j]=sum%10;
		sum/=10;
	}
//	printf("%d\n",s[30]);
	for(i=k;i<n;i++)
	{
		add(s,fi[i-1]);
	//	printf("%d\n",fi[4][30]);
	//	printf("%d\n",s[30]);
		if(i>k) minu(s,fi[i-k-1]);
		int r=0;
		for(r=30;r>=0;r--) fi[i][r]=s[r];
	}
	int k1=0;
	for(k1;s[k1]==0;k1++);
	for(k1;k1<31;k1++) printf("%d",s[k1]);
	printf("\n");
	
	end:
	return 0;
}