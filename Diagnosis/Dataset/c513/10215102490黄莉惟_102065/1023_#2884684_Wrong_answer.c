#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
    char str[110][31];
    int count=0;
    int i=0; 
    while(scanf("%s",str[count])!=EOF)
    {  
       printf("%d\n",number(str[count])) ;
       count++;
    }
    
}
int number(char s[110][31])
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