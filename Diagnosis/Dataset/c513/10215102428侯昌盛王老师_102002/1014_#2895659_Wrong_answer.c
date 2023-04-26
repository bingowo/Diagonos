#include <stdio.h>
#include <string.h>
#include <math.h>
void trans(int a,char b[])
{
	int m,i=0;
	if(a==0) b[i]='0';
	while(a)
	{
		m=a%3;
		b[i]=m+'0';
		a/=3;
		i++;
	}
	
}
int main()
{

	
	long long int m,n;
	scanf("%lld %lld",&m,&n);
	int i,len=0;

	if(m==0) printf("0");
	if((m%n)==0)
	{
		int a[100]={0};
		m=m/n;
	
		i=0;
		while(m){
			n=m%3;
			a[i]=n;
			
			m/=3;
		
			len++;
			i++;
		
		}
		
		for(i=0;i<len;i++)
		{
			if(a[i]==2)
			{
				a[i+1]=a[i+1]+1;
				if(i==len-1)
				{
					a[i+1]=1;
					len++;
				}
			}
			 
			if(a[i]==3)
			{
				a[i]=0;
				a[i+1]=a[i+1]+1;
				if(i==len-1){
					a[i+1]=1;len++;
				}
			}
		}
		for(i=len-1;i>=0;i--) printf("%d",a[i]);
	
	}
	if(m%n!=0)
	{
		char s1[100],s2[100];
		int w=-1,len3;
		trans(m,s1);
		while(n)
		{
			n/=3;
			w++;
		}
		len3=strlen(s1);
		//printf("%d\n",len3);
		//printf("%s\n",s1);
		for(i=0;i<len3;i++)
		{
			if(s1[i]=='2')
			{
				s1[i+1]=s1[i+1]+1;
				if(i==len3-1)
				{
					s1[i+1]='1';
					len3++;
				}
				//printf("%c\n",s1[i+1]);
			}
			 
			else if(s1[i]=='3')
			{
				s1[i]='0';
				s1[i+1]=s1[i+1]+1;
				if(i==len3-1){
					s1[i+1]='1';len3++;
				}
			}
		}
		if(w<len3){
			int n1=0,k1=0;
			while(s1[n1++]==0) k1++;
			for(i=len3-1;i>=n1;i--)
			{
				if(i==w-1) printf(".");
				printf("%c",s1[i]);
			
			}
		}
		else{
			int n2=0,k2=0;
			while(s1[n2++]==0) k2++;
			int e,j=0;
			e=w-len3+1;
			for(j;j<e;j++) s1[j+len3]='0';
			len3=strlen(s1);
			for(i=len3-1;i>=n2;i--)
			{
				if(i==w-1) printf(".");
				printf("%c",s1[i]);
			
			}
		}
		
		
		
	
		
		
		
	}
	
	
	return 0;
	
	
	
}