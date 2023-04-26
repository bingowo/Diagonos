#include<stdio.h>
#include<string.h>
void show3trans(char s[]);

 int main()
 {
 	int T;
 	scanf("%d",&T);
 	int i = 0;
 	char tests[30] ;
 	for(;i < T;i++)
 	{
 		printf("case #%d:\n",i);
		scanf("%s",&tests);
		show3trans(tests);
	 }
	 return 0;
 }
 
 void show3trans(char s[])
 {
 	unsigned int p = 0;
 	long long int ansA = 0,ansB = 0,ansC = 1;
	 //A存放整数部分，B存放小数分子部分，C记录分母 
	for( ;p < strlen(s);p++)
	{
		if(s[p]=='.') break;
		ansA = ansA * 3;//若能读到下一位，则对上一次循环所得数*3
		if(s[p] == '1') ansA++;
		if(s[p] == '-') ansA--; 
	}
	//整数部分读取完成 存储在ansA中
	 printf("%lld\n",ansA);
	 
}	 
}
