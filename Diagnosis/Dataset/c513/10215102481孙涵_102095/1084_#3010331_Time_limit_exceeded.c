 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <math.h>
 #include <string.h>
 
 //数据结构
 /*
 使用结构体存放结果相关数据
 包括多少次方和最后结果
 其中最后结果用整型数组存放 
 注意这里个位在前高位在后面 
 */ 
 
 //思路
 /*
 1.数据的输入以及初始化 
 2.计算
 	2.1 结构-->循环 
 	2.2 过程-->数组每一位乘以2 注意进位
	2.3 数据处理-->找到最后一个不为零的数字 倒序输出 
 3.结果输出 
 4.*/ 
 
struct data{
	int n;
	int ans[10];
};
 

 
int main(){
	int T;
 	scanf("%d",&T);
 	int t;
 	for (t = 0; t < T; t++){
 		//1.数据的输入以及初始化
		  
 		//数据的输入 
 		int n;
		scanf("%d",&n);
		struct data d;
		d.n = n;
		int i;
		
		//初始化结构体 
		for (i = 1; i < 10; i++){
			d.ans[i] = 0;
		}
		d.ans[0] = 1;
		
		//2.计算
		
		//2.1 2.2
		//2.1 结构-->循环 
 		//2.2 过程-->数组每一位乘以2 注意进位
		int carry = 0;//进位 
		int count = 0; //乘了几次 
		for (i = 0; i < 10 && count <= n; i++){
			d.ans[i] = d.ans[i] * 2;
			count ++;
			carry = d.ans[i] / 10;
			d.ans[i] = d.ans[i] % 10;
		} 
		
		
		//2.3 数据处理-->找到最后一个不为零的数字 倒序 
		int pl;
//		for (i = strlen(d.ans - 1); i >= 0; i--){
//			if (d.ans[i] !=)
//		}
		i = 10 - 1;
		while (d.ans[i] == 0){
			pl = i;
		}
		pl = pl - 1;//找到最后一个不为零的数字
		for (i = 0; i <= pl/2; i++){
			int temp = d.ans[i];
			d.ans[i] = d.ans[pl - i];
			d.ans[pl - i] = temp;
		} 
		
		
		//3.结果输出
		printf("case #%d:\n",t);
		for (i = 0; i <= pl; i++){
			printf("%d",d.ans[i]);
		} 
	 }
 }