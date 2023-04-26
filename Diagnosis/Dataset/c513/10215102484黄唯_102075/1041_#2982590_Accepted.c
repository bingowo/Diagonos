//连续判断两个相邻字符是不是一样的 
//2022/4/3

#include<stdio.h>
#include<stdlib.h>
 int main()
 {
 	char s[51];
 	scanf("%s",s);
 	int max = 1;
 	int count = 1;
 	char *p1 = s;
 	char *p2 = s+1;
 	while(*p2)
 	{
	 if(*p1 != *p2)
	 {
	 	count++;
	 }
	 else{
	 	if(count > max) max = count;
	 	
    count  = 1;
	 }
	 p1++;
	 p2++;
	 
	 }
	 if(count > max) max = count;
	 printf("%d",max);
	 return 0;
 }

