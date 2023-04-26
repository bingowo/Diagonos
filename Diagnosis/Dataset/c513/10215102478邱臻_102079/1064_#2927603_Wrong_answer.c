#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double polish_exper(){
	char a[11];
	double f1,f2;
	scanf("%s",a);
	switch(a[0]){
		case '+':
			f1=polish_exper();f2=polish_exper();return f1+f2;
		case '-':
			f1=polish_exper();f2=polish_exper();return f1-f2;
		case '*':
			f1=polish_exper();f2=polish_exper();return f1*f2;
		case '/':
			f1=polish_exper();f2=polish_exper();return f1/f2;
		default:
			return atof(a);  //a是数字 
	}
}

int main() {
	int t,i;
    double result;
	scanf("%d",&t);   //问题数 
	for(i=0;i<t;i++){
		result=polish_exper();
		printf("case #%d:\n",i);
		printf("%.6lf",result);
	} 
	return 0;
}