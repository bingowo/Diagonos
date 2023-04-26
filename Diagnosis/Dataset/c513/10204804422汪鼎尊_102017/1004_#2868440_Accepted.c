#include<stdio.h>

char c(int i)
{
	return i<=9?i+'0':i-10+'a';
}

void pr(char* byte)
{
	printf("%c%c ",c(((*byte)>>4)&0xf),c((*byte)&0xf));
}

int main()
{
	char input[64];
	int type_int;
	double type_double;
	char *p;
	int i,isdouble;
	while(~scanf("%s",&input))
	{
		isdouble=0;
		for(i=0;input[i]!='\0';i++)if(input[i]=='.')
		{
			isdouble=1;
			break;
		}
		if(isdouble)
		{
			sscanf(input,"%lf",&type_double);
			p=(char*)&type_double;
			for(i=0;i<8;i++)pr(p+i);
		}
		else
		{
			sscanf(input,"%d",&type_int);
			p=(char*)&type_int;
			for(i=0;i<4;i++)pr(p+i);
		}
		putchar('\n');
	}
	return 0;
}