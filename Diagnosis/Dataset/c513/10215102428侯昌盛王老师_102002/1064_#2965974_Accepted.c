#include <stdio.h>
#include <stdlib.h>
double h()
{
	char s[11];
	double f1,f2;
	scanf("%s",s);
	switch(s[0]){
		case'+':{f1=h();f2=h();return f1+f2;break;}
		case'-':{f1=h();f2=h();return f1-f2;break;}
		case'*':{f1=h();f2=h();return f1*f2;break;}
		case'/':{f1=h();f2=h();return f1/f2;break;}
		default:return atof(s);
	}
}


int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		double k;
		k=h();
		printf("case #%d:\n",i);
		printf("%.6lf\n",k);
		
	}
	return 0;
}