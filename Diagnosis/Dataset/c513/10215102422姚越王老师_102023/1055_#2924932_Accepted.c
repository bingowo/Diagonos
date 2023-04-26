#include<stdio.h>
int main()
{
	char str[1000001],c;
	scanf("%s",str);
	int m[128];//记录每个字符最后出现的位置 
	int t,i,start=0,len=0;
	for(i=0;i<128;i++)m[i]=-1;
	for(i=0;str[i];i++)
	{
		c=str[i];
		if(m[c]>=t)//m[c]最后出现的位置大于t 
		{
			t=m[c]+1;
			m[c]=i;
		}
		else
		{
			m[c]=i;
			if(len<i-t+1)
			{
				start=t;
				len=i-t+1;
			}
		}
	}
	for(i=0;i<len;i++)
		printf("%c",str[start+i]);
	return 0;
}