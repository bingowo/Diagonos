#include<stdio.h>
#include<string.h>

char str[100001]={0};

int main()
{
	int table[127]={0};
	for(int i='0';i<='9';i++)
		table[i] = i - '0';
	for(int i='a';i<='f';i++)
		table[i] = i - 'a' + 10;
	
	scanf("%s",str);
	int len = strlen(str),pos=0,flag=-1;
	while(pos<len)
	{
		if(str[pos]=='0' && str[pos+1]=='x' && str[pos+2]<='f' && pos < len-2)
		{
			flag=1,pos+=2;
			int temp=0;
			while((str[pos]!='0' || str[pos+1]!='x' || str[pos+2]>'f') && str[pos]<='f' && pos<len)
			{
				temp = temp*16 + table[str[pos++]];
			}
			printf("%d ",temp);	
		}
		else
			pos++;
	}
	if(flag==-1)
		printf("-1\n");
	return 0;
}