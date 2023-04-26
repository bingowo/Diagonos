#include <stdio.h>
#include <string.h>
#define N 500
void trans(int a,int k,int anw[])
{
	while(a)
	{
		anw[k]=a%2;
		a/=2;
		k--;
		
	}
}
int main()
{
	char s[N];
	scanf("%s",s);
	int len,num1,num2,i=0,p=0;
	int f=0,j=11,k=11;
	int anw[100]={0,0,0,1};

	//printf("%d",anw[3]);
	len=strlen(s);
	num1=len/3;
	num2=len%3;
	while(len)
	{
		anw[j]=len%2;
		//printf("%d\n",anw[j]);
		len/=2;
		j--;
	}
	//for(p=0;p<=11;p++) printf("%d",anw[p]);
	
	for(p;p<num1;p++){
	
	
		for(i;i<num1;i++)
		{
			int a;
			a=(s[f]-'0')*100+(s[f+1]-'0')*10+(s[f+2]-'0');
			//printf("%d",a);
			k+=10;
			trans(a,k,anw);
			//for(j=0;j<k;j++) printf("%d",anw[j]);
			
			f+=3;
		}
	}
	if(num2!=0)
	{
		int a;
		if(num2==1)
		{
			
			a=s[f]-'0';
			k+=4;
			trans(a,k,anw);
			
		}
		if(num2==2)
		{
		
			a=(s[f]-'0')*10+(s[f+1]-'0');
			k+=7;
			trans(a,k,anw);
		}
	}
	int m=0;
	for(m;m<=k;m++) printf("%d",anw[m]);
	return 0;
	
}