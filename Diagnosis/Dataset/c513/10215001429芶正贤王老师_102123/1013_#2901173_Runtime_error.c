#include<stdio.h>
#include<string.h>
void showdecimaltrans(char s[]);

 int main()
 {
 	int i = 0;
 	char tests[31] ;
	scanf("%s",&tests);
	showdecimaltrans(tests);
	 return 0;
 }
 
 void showdecimaltrans(char s[])
 {
 	unsigned int p = 0;
 	long long int ansA = 0,ansB = 0,ansC = 1;
	 //A存放整数部分，B存放小数分子部分，C记录分母 
	for( ;p < strlen(s);p++)
	{
		if(s[p] == '.') break;
		ansA = ansA * 3;//若能读到下一位，则对上一次循环所得数*3
		if(s[p] == '1') ansA++;
		if(s[p] == '2') ansA--; 
	}
	//整数部分读取完成 存储在ansA中
	
	p++;//跳过小数点
	
	for( ;p < strlen(s);p++)
	{
		ansB = ansB * 3;
		if(s[p] == '1') ansB++;
		if(s[p] == '2') ansB--;
		ansC = ansC * 3;
	 } 
 	//小数部分读取完成，分子分母分别存储在ansB ansC中 
 	
 	if(ansB < 0 && ansA > 0) 
	 {
	 ansA--;
	 ansB = ansC + ansB;
	 }
 	if(ansB > 0 && ansA < 0) 
	 {
	 ansA++;
	 ansB = ansC - ansB;
	 if(ansA == 0)
	 ansB = -ansB;
	 }
	 
	 
 	
 	long long int gcd,r,m,n;
 	m = ansC>0 ? ansC : -ansC;
 	n = ansB>0 ? ansB : -ansB; 
 	while ((m%n) != 0)
 	{
 		r = m%n;
 		m = n;
 		n = r;
	 }
	 gcd = n;
	 
	 if(ansB == 0) printf("%lld\n",ansA);
	 else 
	 {
	 if(ansA != 0) printf("%lld ",ansA);
	 printf("%lld %lld\n",ansB/gcd,ansC/gcd);	 
	 }	 
}