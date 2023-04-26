#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int t(char c)
{
	if(c=='1')return 1;
	else if(c=='0')return 0;
	else return -1;
}

int main()
{
	int result=0,up=0,down=1,frac=0;
	char input[50];
	int i;
	
	scanf("%s",&input);
	
	for(i=0;input[i]!='\0';i++)
	{
		if(input[i]=='.')
		{
			frac=1;
			continue;
		}
		if(frac==0)
		{
			result*=3;
			result+=t(input[i]);
		}
		else
		{
			down*=3;
			up*=3;
			up+=t(input[i]);
		}
	}//printf("%d %d %d\n",result,up,down);
	
	if(result>0&&up<0)
	{
		result--;
		up=up+down;
	}
	else if(result<0&&up>0)
	{
		result++;
		up=up-down;
	}
	if(result<0&&up<0)up=-up;
	
	//printf("%d %d %d\n",result,up,down);
	
	if(result==0)printf("%d %d",up,down);
	else if(down==1)printf("%d",result);
	else printf("%d %d %d",result,up,down);
	
	return 0;
}