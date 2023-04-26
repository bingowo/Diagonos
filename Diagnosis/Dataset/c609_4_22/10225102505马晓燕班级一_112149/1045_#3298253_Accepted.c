#include <stdio.h> // for cout

int main()
{
	char c;
	int state=0;
	
	while(c=getchar(),c!=EOF)
	{
		switch (state) {
		case 0:
			if(c=='/')	state=1;//可能进入注释
			else if(c=='"')	state=5,putchar(c);//进入字符串
			else if(c=='\'')	state=7,putchar(c);//进入字符
			else		putchar(c);
			break;
		case 1:
			if(c=='/')	state=2;//进入行注释状态
			else if(c=='*')	state=3;//块注释状态
			else		state=0,putchar('/'),putchar(c);
			break;
		case 2:
			if(c=='\n')	state=0,putchar(c);//退出行注释
			break;
		case 3:
			if(c=='*')	state=4;//可能退出块注释状态
			break;
		case 4:
			if(c=='/')	state=0;//退出块注释
			else if(c=='*');
			else        state=3;
// 			else		state=3,cin.putback(c);
			break;
		case 5:
			if(c=='\\')	state=6;//字符串中的转义字符\"=="
			if(c=='"')	state=0;//结束字符串
			putchar(c);
			break;
		case 6:
			state=5;
			putchar(c);
			break;
		case 7:
			if(c=='\\')	state=8;//转义字符
			if(c=='\'')	state=0;//结束字符
			putchar(c);
			break;
		case 8:
			state=7;
			putchar(c);
			break;
		}
	}
	
	return 0;
}