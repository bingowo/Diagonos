#include <stdio.h>
#include <string.h>

int main()
{
	char s[51];
	scanf("%s",s);
	int i,j=0;
	int Rome[128]={0};
	Rome['I']=1;Rome['V']=5;
	Rome['X']=10;Rome['L']=50;    
	Rome['C']=100;Rome['D']=500;
	Rome['M']=1000; 
	long long data[100];
	long long flag=1;
	for(i=0;i<strlen(s)-1;i++)
	{
		switch(s[i])
		{
        	case '(':flag=flag*1000;break;
        	case ')':flag=flag/1000;break;
        	default: data[j++]=Rome[s[i]]*flag; break;
		}
	}
	long long ans=0;
	for(i=0;i<j-1;i++)
	{
		if(data[i]<data[i+1])
		{
			ans-=data[i];
		}
		else{
		ans+=data[i];}
	}
	ans+=data[j-1];
	printf("%lld\n",ans);
	return 0;
}