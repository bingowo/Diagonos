#include <stdio.h>
#define MAXLEN 80
int main()
{
	int i,k; /* i：原字符串下标，k：新字符串下标 */
	long number; /* number：转换结果 */
	char ch,str[MAXLEN],num[MAXLEN]; /* str：原字符串，num：新字符串 */
	printf("请输入一个字符串：");
	i=0;
	
	while((str[i]=getchar())!='\n'&&i<MAXLEN-1) 
		i++;
 	str[i]='\0'; /*置字符串结束标志*/ 
 	
 	for(i=0,k=0;str[i]!='\0';i++)
 		if((str[i]>='0'&&str[i]<='9')||(str[i]>='A'&&str[i]<='F'))
			num[k++]=str[i];
	
 	num[k]='\0'; /* 置新字符串结束标志 */
 	
	/* 将新字符串转换为十进制整数 */
 	for(i=0,number=0;num[i]!='\0';i++){
 		if(num[i]>='0'&&num[i]<='9'){
 			number=number*16+(num[i]-'0'); 
		}
 		else{
 			number = number*16+num[i]-'A'+10; 
		} 
  	}
  	printf("十进制整数=%ld\n",number);
    return 0;
} 
————————————————
版权声明：本文为CSDN博主「wq_冲冲冲」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_42308203/article/details/116609190