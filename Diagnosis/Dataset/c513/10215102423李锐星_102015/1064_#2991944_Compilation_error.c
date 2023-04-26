#include <stdio.h>
#include <math.h>
//
double exp()
{
	char s[11];
	double f1,f2;
	scanf("%s",s);
	switch(s[0]){
		case'+':f1=exp();f2=exp();return f1+f2;
		case'-':f1=exp();f2=exp();return f1-f2;
		case'*':f1=exp();f2=exp();return f1*f2;
		case'/':f1=exp();f2=exp();return f1/f2;
		default:return atof(s);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		printf("%.6f\n",exp());
	}
	return 0;
}