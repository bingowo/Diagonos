

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


 int string_count(char *s)
 {
 	int table[200]={0};
	int count=0;
	for (int i=0;s[i];i++)
	{
		table[s[i]]=1;
	}
	for(int i=1;i<200;i++)
	{
		count+=table[i];
	}
	return count;
 }


int cmp1(const void *a,const void *b)
{
	int num1,num2;
	char *str1,*str2;
	str1=*(char(*)[0])a;
	str2=*(char(*)[0])b;
	num1=string_count(str1);
	num2=string_count(str2);
	if(num1==num2)
		return strcmp(str1,str2);
	else
		return num2-num1;
}


int main()
{
	int T,num,j=0;
	scanf("%d",&T);
	while(T--)
	{
		char input[100][21]={};//如果这里设置20的话，遇到长度为20的字符串时会连续输出下一行的字符串 
		int k=0;
		scanf("%d",&num);
		while(num--)
		{
			scanf("%s",input[k]);
			k++;
		}
		qsort(input,k,sizeof(input[0]),cmp1);
		printf("case #%d:\n",j++);
		for (int i=0;i<k;i++)
		{
			printf("%s\n",input[i]);
		}
	}
	return 0;
}