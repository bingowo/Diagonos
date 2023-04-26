#include <stdio.h>
#include <string.h>

int main()
{
	char s[51];
	scanf("%s",s);
	int i,j=0;
	long long data[100];
	long long flag=1;
	for(i=0;i<strlen(s)-1;i++)
	{
		switch(s[i])
		{
			case 'I':return 1;break;
        	case 'V':return 5;break;
        	case 'X':return 10;break;
        	case 'L':return 50;break;
        	case 'C':return 100;break;
        	case 'D':return 500;break;
        	case 'M':return 1000;break;
        	case '(':flag=flag*1000;break;
        	case ')':flag=flag/1000;break;
        	default: data[j++]=Roma[s[i]]*flag; break;
		}
	}
	long long ans=0;
	for(i=0;i<strlen(data)-1;i++)
	{
		if(data[i]<data[i+1])
		{
			ans-=data[i];
		}
		else:ans+=data[i];
	}
	ans+=data[strlen(data)-1];
	printf("%lld\n",ans);
	return 0;
}