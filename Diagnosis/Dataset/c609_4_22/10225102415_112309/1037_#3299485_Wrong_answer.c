#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000

int main() {
	char s[MAXLEN];
	scanf("%s", s);
	int len = strlen(s);
	
	char t[MAXLEN] = {'\0'};
	char max[MAXLEN] = {'\0'};
	
	int hash[75] = {0};
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (hash[s[i]-48] == 0) {
			hash[s[i]-48] = 1;
			t[j] = s[i];
			j++;
			if (j > strlen(max)) strcpy(max, t);
		} else {
			for (int k = 0; k < 75; k++) hash[k] = 0;
			j = 0; 
		}
	}
	printf("%s", max);
	return 0;
}