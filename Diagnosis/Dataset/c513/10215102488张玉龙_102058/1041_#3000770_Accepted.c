#include<stdio.h>
#include<string.h>
int main()
{
	char s[51];
	int temp=1,num=1;
	scanf("%s",s);
	for(int i=0;i<strlen(s)-1;i++)
	{
		if(s[i+1]!=s[i])
			temp++;
		else
			temp=1;
		if(temp>num)
			num=temp;
	}
	printf("%d",num);
	return 0;	
} 