#include <stdio.h>

int main()
{
	int a[1005]={0};
	int tem,i=0;
	char order;
	order = getchar();
	while(scanf("%d",&tem) != EOF)
	{
		a[tem]++;
		if(tem >= i) i = tem;
	}
	if(order == 'A')
	{
		for(int j=0;j<=i;j++){
			if(a[j] != 0)
				printf("%d%c",j,j == i? '\n':' ');
		}
	}
	else
	{
		for(int j=i;j>=0;j--){
			if(a[j] != 0)
				printf("%d%c",j,j != 0? ' ':'\n');
		}		
	}
	return 0;
}