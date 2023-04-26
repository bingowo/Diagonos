#include<stdio.h>
#include<string.h>

int main()
{
	long long num = 1;
	long long a[26],c[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	char b[26];
	int i = 0;
	scanf("%lld",&a[0]);
	char ch;
	while((ch = getchar())!='\n')
	{
		b[i] = ch;
		i++;
		scanf("%lld",&a[i]);
	}
	b[i] = '\0';
	if(i == 0)
	{
		num = a[i];
	}
	int temp = i;
	for(int j = 0; j < i; j++)
	{
		num = num * a[j] * c[temp-1] + a[j+1];
		temp--;
	}
	printf("%lld\n",num);
	return 0;
}

