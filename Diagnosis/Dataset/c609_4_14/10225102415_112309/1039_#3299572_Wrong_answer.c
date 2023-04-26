#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int T;
	scanf("%d", &T);
	char s1[100];
	char s2[100];
	char s[100];
	for(int i = 0; i < T; i++) {
		scanf("%s", s1); int len1 = strlen(s1);
		scanf("%s", s2); int len2 = strlen(s2);
		scanf("%s", s); int len = strlen(s);
		
		int pos = -1; //正式开始计数的位置 
		int max = 0;
		for (int j = 0; j < len; j++) {
			if (s[j] == s1[0]) {
				char tmp[100] = {'\0'};
				for (int k = 0; k < len1; k++) tmp[k] = s[j+k];
				if (strcmp(tmp, s1) == 0) { pos = j+len1; break; } 
			}
		}
		if (pos == -1) max = 0;
		else {
			for (int j = pos; j < len; j++) {
				if(s[j] == s2[0]){
					char tmp[100] = {'\0'};
					for (int k = 0; k < len2; k++) tmp[k] = s[j+k];
					if (strcmp(tmp, s2) == 0) max = j - pos;
				}	 
			}
		}
		printf("case #%d:\n", i);
		//printf("pos:%d\n", pos);
		printf("%d\n", max);
	}
}