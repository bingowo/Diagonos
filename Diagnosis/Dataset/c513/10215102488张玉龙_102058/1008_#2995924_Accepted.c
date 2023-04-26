#include<stdio.h>
#include<string.h>

int main()
{
	int x,y,n,k1,k2,sum,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		char string1[50]={"\0"};
		k1=0;
		while(x>0)
		{
			string1[k1]=x%2+48;
			x/=2;
			k1++;
		}
		char string2[50]={"\0"};
		k2=0;
		while(y>0)
		{
			string2[k2]=y%2+48;
			y/=2;
			k2++;
		}
		sum=0;
		for(int j=0;j<strlen(string1)&&j<strlen(string2);j++)
		{
			if(string1[j]!=string2[j])
				sum++;
		}
		if(strlen(string1)>strlen(string2))
		{
			for(k=strlen(string2);k<strlen(string1);k++)
				if(string1[k]==49)
					sum++;
		}
		else
			for(k=strlen(string1);k<strlen(string2);k++)
				if(string2[k]==49)
					sum++;
		printf("%d\n",sum);
		}
}