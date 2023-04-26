#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double expr()
{  double f1,f2;
	char c[200]={'0'};
	scanf("%s",c);
	switch(c[0])
	{ case '+':{f1=expr();f2=expr();return f1+f2;}
	case '-':{f1=expr();f2=expr();return f1-f2;}
	case '*':{f1=expr();f2=expr();return f1*f2;}
	case '/':{f1=expr();f2=expr();return f1/f2;}
	default: return atof(c);
	}
}
int main()
{    int k,T;
    scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{   double va;
		printf("case #%d:\n",k);
		va=expr();
		printf("%lf\n",va);
	}
	return 0;
}
 
