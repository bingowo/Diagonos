#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		int a,n;
		scanf("%d %d",&a,&n);
		printf("case #%d:\n",i);
		if(n == 0)
			printf("%d\n",1);
		int p[101] = {0};
		p[100] = a;                                      //n = 1
		for(int j = 2;j <= n;j++){
			int remainder = 0;
			for(int k = 100;k >= 101-j;k--){
				p[k] = p[k] * a + remainder;
				remainder = p[k] / 10; 
				p[k] %= 10;
			}
		}
		int flag = 0;
		for(int k = 0;k < 101;k++){
			if(p[k] != 0)
				flag = 1;
			if(flag && n != 0)
				printf("%d",p[k]);
		}
		printf("\n");
	}
	return 0;
}