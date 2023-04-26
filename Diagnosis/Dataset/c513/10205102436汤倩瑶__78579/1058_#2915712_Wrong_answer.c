#include<stdio.h>
void dfa();

 int main(void)
 {    dfa();
     return 0;
 }

 void dfa()
 {
	char c;
	int state=0;

	while((c=getchar())!=EOF)
	{
		switch(state)
		{
		case 0:
			if(c=='/')// ex. [/]
				state=1;
			else if(c=='\'')// ex. [']
				state=6;
			else if(c=='\"')// ex. ["]
				state=8;
			else
				putchar(c);
			break;
		case 1:
			if(c=='*')// ex. [/*]
				state=2;
			else if(c=='/')// ex. [//]
				state=4;
			else
			{ // ex. [<secure/_stdio.h> or 5/3]
				putchar('/');
				putchar(c);
				state=0;
			}
			break;
		case 2:
			if(c=='*') // ex. [/*he*]
				state=3;
			else // ex. [/*heh]
				state=2;
			break;
		case 3:
			if(c=='/')// ex. [/*heh*/]
				state=0;
			else if(c=='*')
				state=3;//ex. [/***]注意这里，不加这个条件，*的个数是奇数的时候出错
			else// ex. [/*heh*e]
				state=2;
			break;
		case 4:
			if(c=='\\')// ex. [//hehe\]
				state=5;
			else if(c=='\n')// ex. [//hehe<enter>]
			{
				state=0;
				putchar(c);
			}
			break;
		case 5:
			if(c=='\\')// ex. [//hehe\\\\\]
				state=5;
			else// ex. [//hehe\<enter> or //hehe\a]
				state=4;
			break;
		case 6:
			if(c=='\\')// ex. ['\]
				state=6;
			else if(c=='\'')// ex. ['\n' or '\'' or '\t' ect.]
			{
				state=0;
				putchar(c);
			}
			break;
		
		case 8:
			if(c=='\\')// ex. ["\]
				state=8;
			else if(c=='\"')// ex. ["\n" or "\"" or "\t" ect.]
			{
				state=0;
				putchar(c);
			}
			break;
		
		
		}
		if(state==6||state==8)
			putchar(c);
	}

}