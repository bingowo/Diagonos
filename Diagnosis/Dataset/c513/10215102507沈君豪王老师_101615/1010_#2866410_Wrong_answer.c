#include <stdio.h>
#include <string.h>
#include <math.h>

void itob(unsigned n, char s[], int length)
{ 
	int i;
	for(i = 98; n && i; n /= 2){
		s[i--] = (((n % 2) < 10) ? '0' : ('A' - 10)) + (n % 2);
	}
	memmove(s , s + i + 1, 99 - i- 1);
	s[99 - i- 1] = '\0';
	int len = strlen(s);
	int diff;
	if(len < length){
		diff = length - len;
		memmove(s + diff, s, len + 1);
		memset(s, '0', diff);
	}
}

int main(void)
{
	char s[501], out[10000] = {'0','0','0','1', '\0'}, temp[11];
	scanf("%s", s);
	int tempnum = 0, len = strlen(s);
	itob(len, temp, 10);
	strcat(out, temp);
	for(int i = 0 ; i < len; i ++){
		tempnum = tempnum * 10 + (s[i] - '0');
		if(i % 3 == 2){
			itob(tempnum, temp, 10);
			strcat(out, temp);
			tempnum = 0;
		}
	}
	if(len % 3 == 1){
		itob(tempnum, temp, 4);
		strcat(out, temp);
		tempnum = 0;
	}else if(len % 3 == 2){
		itob(tempnum, temp, 7);
		strcat(out, temp);
		tempnum = 0;
	}
	printf("%s\n", out);
	
	return 0;
}