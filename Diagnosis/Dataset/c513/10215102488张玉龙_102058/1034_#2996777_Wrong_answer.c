#include<stdio.h>
#include<string.h>
int main()
{
	int n,j,k;
	double a[200]={0};
	char s[100]={"\0"},temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
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
				}
			}
		}
		printf("%s\n",s);
	}
}