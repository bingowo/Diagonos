#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//这个我觉得可以近似看作之前那个2的n次方的变种
//但是这里需要注意的一点是数据范围
//我愿意称之为
//2^n ultra plus pro max  

struct data{
	int a; 
	int n;
	int ans[95];
};

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int t;
	for (t = 0; t < T; t++){
		int a;//底数 
		int n;//指数
		scanf("%d %d", &a, &n);
		struct data d;
		d.n = n;
		int i;
		
		//初始化结构体 
		for (i = 1; i < 95; i++){
			d.ans[i] = 0;
		}
		d.ans[0] = 1;
		
		//2.计算
		
		//2.1 2.2
		//2.1 结构-->循环 
 		//2.2 过程-->数组每一位乘以2 注意进位
		int carry = 0;//进位 
		int count = 0; //乘了几次 
		for (count = 0; count < n; count++) {
			for (i = 0; i < 95; i++){
				d.ans[i] = d.ans[i] * a;
				d.ans[i] = d.ans[i] + carry; 
				carry = d.ans[i] / 10;
				d.ans[i] = d.ans[i] % 10;
			} 
		}
		
		//2.3 数据处理-->找到最后一个不为零的数字 倒序 
		int pl;
		i = 95 - 1;
		pl = 95;;
		while (d.ans[i] == 0){
			pl = i;
			i--;
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
		printf("\n");
	}
	return 0;
}