#include <stdio.h>
#include <stdlib.h>

char in[10000006];

int main() {
	enum {
		status0 = 0,
		status1 = 1,
		status2 = 2,
		status3 = 3,
		status4 = 4,
		status5 = 5,
		status6 = 6,
		status7 = 7,
		status8 = 8,
	} state;
	char c;
	int i = 0;
	while ((c = getchar()) != EOF)
		in[i++] = c;
	char ch, temp;
	state = status0;
	char h = '\n';
	int j = 0;
	while (j<i-1) {
		ch=in[j++];
		switch (state) {
			case 0:
				if (ch == '\\') {
					putchar(ch);
					state = status7;
				} else if (ch == '\"') {
					state = status6;
					putchar(ch);
				} else if (ch == '/') {
					state = status1;
					temp = ch;
				} else
					putchar(ch);
				break;
			case 1:
				if (ch == '*')
					state = status2;
				else if ( ch == '/' )
					state = status5;
				else {
					state = status0;
					putchar(temp);
					putchar(ch);
				}
				break;
			case 2:
				if (ch == '*')
					state = status3;
				break;
			case 3:
				if (ch == '/')
					state = status4;
				else if (ch == '*')
					state = status3;
				else
					state = status2;
				break;
			case 4:
				if (ch == '/')
					state = status1;
				else {
					putchar(ch);
					state = status0;
				}
				break;
			case 5:
				if (ch == '\n') {
					putchar(h);
					state = status0;
				}
				break;
			case 6:
				putchar(ch);
				if (ch == '\\')
					state = status8;
				else if (ch == '\"')
					state = status0;
				break;
			case 7:
				putchar(ch);
				state = status0;
				break;
			case 8:
				putchar(ch);
				state = status6;
				break;
			default:
				break;
		}
	}
	return 0;
}


