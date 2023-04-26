#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double expr();
int main(){
	int T;
	scanf("%d",&T);
	int i=0;
	for(;i<T;i++)
	{
		double x=expr();
		printf("case #%d:\n%.6f\n",i,x);
	} 
	return 0;
}
double expr()
		{ 
			char a[10]; 
			double f1, f2; 
			scanf("%s", a); 
			switch(a[0])
			{ 
			case'+': {f1= expr( ); f2 = expr( ); return f1 + f2;}
			case'-': {f1= expr( ); f2 = expr( ); return f1 - f2;}
			case'*': {f1= expr( ); f2 = expr( ); return f1 * f2;}
			case'/': {f1= expr( ); f2 = expr( ); return f1 / f2;}
			default: return atof(a);
			}
		}
