#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double expr(char a){
	double f1,f2;
	switch(a[0]){  //如为算符，处理其后的波兰式并计算
       case'+': {f1=expr(a++); f2=expr(a+2);a=a+2; return f1+f2;} 
       case'-': {f1=expr(a++); f2=expr(a+2); a=a+2;return f1-f2;}
       case'*': {f1=expr(a++); f2=expr(a+2); a=a+2；return f1*f2;}
       case'/': {f1=expr(a++); f2=expr(a+2); a=a+2；return f1/f2;}
       default: return atof(a);  //不是算符就转换为双精度数
   }
}

	
int main(int argc, char *argv[]) {
	int n,k;
	double ans;
	char a[10000];
	scanf("%d",&n);
	getchar();
	for(k=0;k<n;k++){
		gets(a);
		getchar();
		printf("case #%d:\n",k);
		ans=expr(a);
		printf("%f\n",ans);
	}
	return 0;
}