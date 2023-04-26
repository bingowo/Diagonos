#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    char str[110][31];
    int count=0;
    int i=0; 
    while(scanf("%s",str[count])!=EOF)
    {count++;}
    for(i=0;i<count;i++){
        printf("%s%c",str[i],i==count-1?'\n':' ');
    }
}
int number(char s[110])
{
	int sum=0,flag=0;
	int i;
	int len=strlen(s);
	for(i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){ //提取字符串中的数字
		  sum=10*sum+s[i]-48;
		  flag=1;
		}
	}
	if(flag==0) sum=-1; //如果字符串中没有数字，则返回-1
	return sum;
}
int strnumcmp(const void *a,const void *b)
{
	int number1,number2;
	char *str1,*str2;
	str1=*(char*)a; str2=*(char*)b;
	number1=number(str1);
	number2=number(str2);
	if(number1==number2)
		return strcmp(str1,str2);
	else
		return number1-number2;
}
void Sort(char *str, int count)
{
    qsort(str,count,sizeof(str[0]),strnumcmp);
}