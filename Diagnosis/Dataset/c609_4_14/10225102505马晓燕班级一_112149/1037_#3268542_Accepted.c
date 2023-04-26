#include<stdio.h>
#include<string.h>

char str[1000002]={0};
char ret[1000002]={0};
char ans[1000002]={0};

int main()
{
	scanf("%s",str);
	char count[127]={0};
	long long len = strlen(str);
	long long max=1,temp=1,pos=1,i=0,beg=0;
	ans[0]=str[0],ret[0]=str[0];
	count[ret[0]]++;
	while(i<len-1)
	{
		if(str[i]!=str[i+1] && count[str[i+1]] == 0)//不重复
		{
			ret[pos++]=str[i+1];
			count[str[i+1]]++;
			temp++;
		}
		else
		{
			char* p = memchr(&str[beg],str[i+1],temp);
			i = beg + (p - &str[beg]);
			if(temp > max)
			{
				max = temp;
				for(int i=0;i<max;i++)
					ans[i]=ret[i];
			}
			temp = 1,pos = 0;
			ret[pos++]=str[i+1];
			beg=i+1;
			for(int i=0;i<127;i++)
				count[i]=0;
			count[str[i+1]]++;
		}
		i++;
	}
	if(temp > max)
	{
		max = temp;
		for(int i=0;i<max;i++)
			ans[i]=ret[i];
	}
	ans[max]='\0';
	printf("%s\n",ans);
	
	return 0;
}