#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char str[200][100];
int number(char *s)
{
	int sum=0,flag=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
        if(s[i]>='0'&&s[i]<='9')
		{  
			sum=10*sum+s[i]-'0'; 
			flag=1;
		}
	if(flag==0) 
		sum=-1; 
	return sum;
}
int strnumcmp(const void *e1,const void *e2)
{
    int number1,number2;
	char *str1,*str2;
	str1=*(char (*)[100])e1; str2=*(char (*)[100])e2;
	number1=number(str1);
	number2=number(str2);
	if(number1==number2)
		return strcmp(str1,str2);
	else
		return number1-number2;
}
int main()
{
	int count=0;
    while(scanf("%s",str[count++])!=EOF);
    count--;
    qsort(str,count,sizeof(str[0]),strnumcmp);
    for(int i=0;i<count;i++)
		printf("%s ",str[i]);
	return 0;
}