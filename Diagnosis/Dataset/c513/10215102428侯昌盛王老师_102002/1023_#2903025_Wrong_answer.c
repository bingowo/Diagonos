#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int number(char *s)
{
	int len=strlen(s),i,sum=0,k=0;
	for(i=0;i<len;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			sum=sum*10+s[i]-48;
			k=1;
		}
		i++;
		
	}
	if(k==1) return sum;
	else{
		sum=-1;
		return sum;
	}
}
int strnumcmp(const void *a,const void *b)
{
	char *str1,*str2;
	str1=(char*)a;str2=(char*)b;
	int str1_num,str2_num;
	str1_num=number(str1);
	str2_num=number(str2);
	if(str1_num>str2_num) return 1;
	else
	{
		if(str1_num>str2_num) return 1;
		else return -1;
	}
	
}
int main()
{
	char a[110][40];
	int count=0;
	while(~scanf("%s",a[count])) count++;
	qsort(a,count,sizeof(a[0]),strnumcmp);
	int i=0;
	for(i;i<count;i++) printf("%s ",a[i]);
	return 0;

}