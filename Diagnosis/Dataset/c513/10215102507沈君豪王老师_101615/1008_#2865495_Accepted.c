#include <stdio.h>
#include <string.h>
#include <math.h>

void itob(int n, char s[])
{ 
	int i;
	for(i = 98; n && i; n /= 2){
		s[i--] = (((n % 2) < 10) ? '0' : ('A' - 10)) + (n % 2);
	}
	memmove(s , s + i + 1, 99 - i- 1);
	s[99 - i- 1] = '\0';	
}


int main(void)
{
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		char sx[100], sy[100];
		itob(x, sx);
		itob(y, sy);
		int len1 = strlen(sx), len2 = strlen(sy), cnt = 0, diff = 0;
		if(len1 > len2){
			diff = len1 - len2;
			for(int j = 0 ; j < diff; j ++){
				if(sx[j] != '0'){
					cnt ++;
				}
			}
			for(int j = 0; sy[j]; j ++){
				if(sx[j + diff] != sy[j]){
					cnt ++;
				}
			}
		}else if(len1 < len2){
			diff = len2 - len1;
			for(int j = 0 ; j < diff; j ++){
				if(sy[j] != '0'){
					cnt ++;
				}
			}
			for(int j = 0; sx[j]; j ++){
				if(sy[j + diff] != sx[j]){
					cnt ++;
				}
			}
		}else{
			for(int j = 0; sx[j]; j ++){
				if(sy[j + diff] != sx[j]){
					cnt ++;
				}
			}
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}