#include <stdio.h>

void rem(int c)
{
	int d;
	if(c=='/'){
		if((d=getchar())=='*')
		{
			while((c=getchar())!='*'&&(d=getchar())!='/');
			d=getchar();
		}
		else if(d=='/') while((d=getchar())!='\n');
		else{
			putchar(c);
			putchar(d);
		}
	}
	else putchar(c);
}
int main()
{
	int c;
	c=0;
	while((c=getchar())!=EOF) rem(c);
	return 0;
}