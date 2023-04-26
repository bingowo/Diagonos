#include <stdio.h>
#include <string.h>
void trans(int a,char b[])
{
	int m,i=0;
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

	
	int m,n;
	scanf("%d %d",&m,&n);
	int i,len=0;

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
				a[i+1]=a[i]+1;
				if(i==len-1)
				{
					a[i+1]=1;
					len++;
				}
			}
			 
			if(a[i]==3)
			{
				a[i]=0;
				a[i+1]=a[i]+1;
				if(i==len-1){
					a[i+1]=1;len++;
				}
			}
		}
		for(i=len-1;i>=0;i--) printf("%d",a[i]);
	
	}
	if(m%n!=0)
	{
		int k,p;
		char s1[100],s2[100];
		k=m/n;
		p=n-m*k;
		trans(k,s1);trans(p,s2);
		int len2=strlen(s2);
		strcpy(s2,s1);
		int len3=strlen(s2);
		for(i=0;i<len3;i++)
		{
			if(s2[i]=='2')
			{
				s2[i+1]=s2[i]+1;
				if(i==len3-1)
				{
					s2[i+1]=1;
					len3++;
				}
			}
			 
			if(s2[i]=='3')
			{
				s2[i]='0';
				s2[i+1]=s2[i]+1;
				if(i==len3-1){
					s2[i+1]=1;len3++;
				}
			}
		}
		for(i=len3-1;i>=0;i--)
		{
			if(i==len2-1) printf(".");
			printf("%c",s2[i]);
			
		}
		
	
		
		
		
	}
	
	
	return 0;
	
	
	
}