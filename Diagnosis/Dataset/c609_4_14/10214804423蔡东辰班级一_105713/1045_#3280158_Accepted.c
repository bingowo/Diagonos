#include <stdio.h>
int main(){
	char c;
	int state = 0;
	while((c = getchar()) != EOF){
		switch(state){
			case 0:
			//遇到第一个/时，去1，如果遇到引号，去一个引号状态
				if(c == '/'){state = 1; break;}
				if(c == '\"'){putchar(c) ; state = 5; break;}
				if(c == '\''){putchar(c); state = 5; break;}
				putchar(c); break;
			case 1://可能遇到/和*
				if(c == '/'){state = 4; break;}
				else if(c == '*'){state = 2; break;}
				else{putchar('/'); putchar(c); state = 0; break;}
			case 2:
			//现在已经有了/*，在遇到*时，我需要转到状态3
				if(c == '*'){state = 3; break;}
				break;
			case 3:
			//现在是/**，我需要判断接受到的是/还是其他的
				if(c == '/'){state = 0; break;}
				else if(c == '*'){state = 3; break;}
				else{state = 2; break;}//为了避免在/*中因为一些额外的字符断掉，然后又输入/，其实就是为了保证遇到的/左边一定是*
				break;
			case 4:
			//现在是 //，只需要碰到换行符我就回到0.
				if(c == '\n'){state = 0; putchar(c); break;}//记得写入换行符
				break;
			case 5:
			//引号内内容，需要判断反义序列。
				if(c == '\\'){putchar(c); state = 6; break;}
				if(c == '\"'){putchar(c); state = 0; break;}
				if(c == '\''){putchar(c); state = 0; break;}
				putchar(c);
				break;
			case 6:
				putchar(c);//自动把反义序列之后的放进去
				state = 5;
				break;
		}
	}
	return 0;
}