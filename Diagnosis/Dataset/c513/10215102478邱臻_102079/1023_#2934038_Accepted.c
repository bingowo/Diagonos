#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int number(char* str);
int strnumcmp(const void *a,const void *b)
{
	int number1,number2;
	char *str1,*str2;
	str1=*(char (*)[31])a; str2=*(char (*)[31])b;
	number1=number(str1);
	number2=number(str2);
	if(number1==number2)
		return strcmp(str1,str2);
	else
		return number1-number2;
}

int number(char *s)
{
	int sum=0,flag=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
                    if(s[i]>='0'&&s[i]<='9') //提取字符串中的数字
		{  sum=10*sum+s[i]-48; flag=1;
		}
	if(flag==0) sum=-1; //如果字符串中没有数字，则返回-1
	return sum;
}
    //提取字符串末尾数字 
int main() {
	char str[110][31];
     int count=0,i;
     while(scanf("%s",str[count])!=EOF)
          {count++;}

	qsort(str,count,sizeof(str[0]),strnumcmp);

	for(i=0;i<count;i++)
		printf("%s%c",str[i],i==count-1?'\n':' ');

	
	return 0;
}