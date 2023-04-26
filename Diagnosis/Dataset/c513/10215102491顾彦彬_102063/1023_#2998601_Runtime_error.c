#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nums(char *s)
{
	int flag=0,sum=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			flag=1;
			sum=10*sum+s[i]-'0';
		}
	}
	if (flag==0)
		sum=-1;
	return sum;
}

int cmp1(const void *a,const void *b)
{
	int num1,num2;
	char *str1,*str2;
	str1=*(char*)a;//这里的31指的是每行最后的字符串结束符 
	str2=*(char*)b;
	num1=nums(str1);
	num2=nums(str2);
	if (num1==num2)
		return strcmp(str1,str2);
	else
		return num1-num2;
}

main()
{
	char str[110][31];
	     int count=0;
	     while(scanf("%s",str[count])!=EOF)
	          {count++;}
	qsort(str,count,sizeof(str[0]),cmp1);
	/*for(int i=0;i<=5;i++)
	{
		printf("%d",nums(str[i]));
	}*/
	for (int i=0;i<count;i++)
	{
		printf("%s%c",str[i],i==count-1?'\n':' ');
	}
}