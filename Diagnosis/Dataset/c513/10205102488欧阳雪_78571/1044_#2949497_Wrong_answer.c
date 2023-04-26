#include<stdio.h>
#include<string.h>
#include<math.h>
long SixtTen(char *s)
{
	int i,t;             //t记录临时加的数 
	long sum =0;
	for(i=0;s[i];i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		t=s[i]-'0';       //当字符是0~9时保持原数不变
		if(s[i]>='a'&&s[i]<='z')
		t=s[i]-'a'+10;
		if(s[i]>='A'&&s[i]<='Z')
		t=s[i]-'A'+10;
		sum=sum*16+t;
	}
	return sum;
 } 
int main()
{
	char s[100001]={0};
	scanf("%s",s);
	char c;
	int i=0,j=0,flg=0;
	int ten[1000]={0};
	while(s[i])
	{
		if(s[i]=='0'&&s[i+1]=='x')
		{
			flg=1;
			i+=2;
			char sixt[1000]={0};
			int k=0;
			while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f'))
			{
				sixt[k++]=s[i];
				i++;
			}
			ten[j++]=SixtTen(sixt);
		}
		i++;
	}
	if(flg==0)
	{
		printf("-1");
	}
	else
	for(int t=0;t<j;t++)
	{
		printf("%d ",ten[t]);
	}
}