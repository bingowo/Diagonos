#include<stdio.h>
#include<string.h>

int main() {
	char ch; 
	while ((ch=getchar()) != EOF) {
		if (ch == '"'||ch=='\'') {
			char ch1;
			putchar(ch);
			while ((ch1 = getchar()) != ch) {
				putchar(ch1);
				if (ch1 == '\\') {
					char cha;
					cha = getchar();
					putchar(cha);
				}	
			}
			putchar(ch1);
		}
		else if (ch == '/') {
			char ch2;
			ch2 = getchar();
			if (ch2 == '*') {
				char tmp1, tmp2;
				tmp1 = getchar();
				tmp2 = getchar();
				while (tmp1!='*'||tmp2!='/')
				{
					tmp1 = tmp2;
					tmp2 = getchar();
				}
			}
			else {
				putchar(ch);
				putchar(ch2);
			}
		}
		else {
			putchar(ch);
		}
	}
	return 0;
}
