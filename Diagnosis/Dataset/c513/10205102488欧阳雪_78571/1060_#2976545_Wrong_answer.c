#include<stdio.h>
#include<string.h>
int main()
{
	char s[101]={0};
	gets(s);
	int i=0,j=0;
	int count[200]={0};
	while(s[i])
	{
		while(s[i]>='1'&&s[i]<='9')
		{
			i++;
			count[j]++;
		}
		i++;
		j++;
	}
	int max=count[0];
	for(int k=0;k<j;k++)
	{
		if(count[k]>max){
			max=count[k];
		}
	}
	printf("%d",max);
}