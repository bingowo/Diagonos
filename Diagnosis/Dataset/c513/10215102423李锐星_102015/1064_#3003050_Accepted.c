#include <stdio.h>
#include <stdlib.h>

double exp()
{
	char s[101];
	scanf("%s",s);
	switch(s[0]){
		case '+':{
			return exp()+exp();
			break;
		}
		case '-':{
			return exp()-exp();
			break;
		}
		case '*':{
			return exp()*exp();
			break;
		}                           
		case '/':{
			return exp()/exp();
			break;
		}
		default:{
			return atof(s);
			break;
		}
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