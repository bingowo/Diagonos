#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//思路:直接统计n!阶乘中出现了多少次因数5即可，根本不用弄大数据

int main(int argc, char *argv[]) {
	int T;
	scanf("%d",&T);
	int t;
	for (t = 0; t < T; t++){
		int num; 
		scanf("%d",&num);
		int count = 0;
		int i;
		for (i = 1; i <= num; i++){
			int n = i;
			while (n > 0){
				int a = n / 5;
				if (n - ( 5 * a ) == 0){
					count ++;
					n = n / 5;
				}else{
					break;
				}
			} 
		}
		printf("case #%d:\n",t);
		printf("%d\n",count);
	}
	return 0;
}