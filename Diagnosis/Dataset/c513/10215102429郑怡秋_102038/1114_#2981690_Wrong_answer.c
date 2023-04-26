#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void cor(char ind[],int a[])
{
	int l=strlen(ind);
	int i=0;
	int sign=1;
	if(ind[i]=='-') sign=-1;
	while(i<=l)
	{
		int an=0;
		while(isdigit(ind[i]))
		{
			an=an*10+ind[i++]-'0';
		}
		if(isalpha(ind[i]))
		{
			if(an==0) an=1;
			if(ind[i+1]=='^') a[ind[i+2]-'0']=an*sign;
			else a[1]=an*sign;
		}
		if(ind[i]=='-')
		{
			sign=-1;
		}
		else if(ind[i]=='+')
		{
			sign=1;
		}
		if(i==l&&isdigit(ind[i-1])&&(ind[i-2]!='^'||ind[i-2]!='^'))
		{
			a[0]=an*sign;
		}
		i++;
	}

}
int main()
{
	char s[20];
	scanf("%s",s);
	int a[10];
	cor(s,a);
	int a1,c1,a2,c2;
	if(a[1]==0) printf("No Answer!\n");
	else
	{
		int an[200][5],cn[200][5];
		int k1=0,k2=0,sign1=1,sign2=1;
		//
		if(a[2]<0) sign1=-1,a[2];
		for(int i=1;i*i<=abs(a[2]);i++)
		{
			if(a[2]%i==0) an[k1][0]=i,an[k1][1]=a[2]/i,k1++;
		}
		
		
		if(sign1==-1)
		{
			for(int i=k1;k1<2*i;k1++)
			{
				an[k1][0]=-an[k1-i][0];
				an[k1][1]=-an[k1-i][1];
			}
		}
		//for(int i=0;i<k1;i++) printf("%d %d\n",an[i][0],an[i][1]);

		//
		if(a[0]<0) sign2=-1;
		for(int i=1;i*i<=abs(a[0]);i++)
		{
			if(a[0]%i==0) cn[k2][0]=i,cn[k2][1]=a[0]/i,k2++;
		}
		if(sign2==-1)
		{
			for(int i=k2;k2<2*i;k2++)
			{
				cn[k2][0]=-cn[k2-i][0];
				cn[k2][1]=-cn[k2-i][1];
			}
		}
		//for(int i=0;i<k2;i++) printf("%d %d\n",cn[i][0],cn[i][1]);

		
		//
		int tump=0;
		for(int i=0;i<k1;i++)
		{
			for(int j=0;j<k2;j++)
			{
				if(an[i][0]*cn[i][0]+an[i][1]*cn[i][1]==a[1]) 
				{
					int a0,c0;
					a1=an[i][0];c2=cn[i][0];a2=an[i][1];c1=cn[i][1];
					if(a1>a2) a0=a1,a1=a2,a2=a0,c0=c1,c1=c2,c2=c0;
					else if(a1==a2&&c1>c2)  c0=c1,c1=c2,c2=c0;
					tump=1;
					break;
				}
				else if(an[i][1]*cn[i][0]+an[i][0]*cn[i][1]==a[1])
				{
					int a0,c0;
					a1=an[i][1];c2=cn[i][0];a2=an[i][0];c1=cn[i][1];
					if(a1>a2) a0=a1,a1=a2,a2=a0,c0=c1,c1=c2,c2=c0;
					else if(a1==a2&&c1>c2)  c0=c1,c1=c2,c2=c0;
					tump=1;
					break;
				}
			}
			if(tump!=0) break;
		}
		printf("%d %d %d %d\n",a1,c1,a2,c2);
		
	}
	return 0;
}