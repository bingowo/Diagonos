#include<stdio.h>
#include<string.h>
int main()
{
	int n,j,k,i2;
	double a[200]={0};
	char s[100]={"\0"},temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(i2=0;i2<200;i2++)
		{
			a[i]=0;
		}
		j=65,k=97;
		for(j;j<=90;j++)
		{
			scanf("%lf",&a[j]);
			a[k]=a[j];
			k++;
		}
		scanf("%s",s);
		for(j=0;j<strlen(s);j++)
		{
			for(k=j+1;k<strlen(s);k++)
			{
				if(a[s[j]]<a[s[k]])
				{
					temp=s[j];
					s[j]=s[k];
					s[k]=temp;
				}
				else if(a[s[j]]==a[s[k]])
				{
					if(s[k]<s[j])
					{
						temp=s[j];
						s[j]=s[k];
						s[k]=temp;
					}
					if(s[k]-s[j]==32)
					{
						temp=s[j];
						s[j]=s[k];
						s[k]=temp;
					}
				}
			}
		}
		printf("case #%d:\n%s\n",i,s);
	}
}