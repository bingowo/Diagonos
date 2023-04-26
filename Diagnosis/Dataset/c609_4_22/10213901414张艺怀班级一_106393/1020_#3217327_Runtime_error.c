#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char*s;
} string;


int isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

int hasDigit(string s)
{
	char* str = s.s;
	for (int i = 0; i < strlen(str); i++) {
		if (isDigit(str[i])) return 1;
	}
	return 0;
}

int toDigit(char c) 
{
	return c - '0';
}

int compare_digit(string s1, string s2)
{
	int low1 = 0, upp1 = 0;
	int low2 = 0, upp2 = 0;
	for (int i = 0; i < strlen(s1.s); i++) {
		if (isDigit(s1.s[i])) {
			low1 = i;
			break;
		}
	}
	for (int i = low1+1; i < strlen(s1.s) - 1; i++) {
		if (!isDigit(s1.s[i])) {
			upp1 = i-1;
			break;	
		}
	}
	
	for (int i = 0; i < strlen(s2.s); i++) {
		if (isDigit(s2.s[i])) {
			low2 = i;
			break;
		}
	}
	
	for (int i = low1+1; i < strlen(s2.s) - 1; i++) {
		if (!isDigit(s1.s[i])) {
			upp2 = i-1;
			break;	
		}
	}
	char nums[10] = {0};
	memcpy(nums, s1.s+low1, (upp1-low1 + 1)*sizeof(char));
	int s1_num = atoi(nums);
	
	memset(nums, 0, 10 * sizeof(char));
	
	memcpy(nums, s2.s+low2, (upp2-low2 + 1)*sizeof(char));
	int s2_num = atoi(nums);
	return s1_num - s2_num;
}

int strnumcmp(string s1, string s2)
{
	if (!hasDigit(s1) && !hasDigit(s2)) return strcmp(s1.s, s2.s);
	else {
		if (!hasDigit(s1)) return -1;
		else if (!hasDigit(s2)) return 1;
		else {
			return compare_digit(s1, s2);
		}
	}
}

int cmp(const void* a, const void* b)
{
	return strnumcmp(*(string*)a, *(string*)b);
}

int main()
{
	string* strs = (string*)malloc(100 * sizeof(string));
	for (int i = 0; i < 100; i++) {
		strs[i].s = (char*)malloc(32 * sizeof(char));
	}
	int i = 0;
	char temp[40] = {0};
	while (scanf("%s", temp) != EOF) {
		strcpy(strs[i].s, temp);
		i++;
	}

	qsort(strs, i-1, sizeof(string), cmp);
	for (int j = 0; j < i-1; j++) {
		printf("%s ", strs[j].s);
	}
	for (int i = 0; i < 100; i++) {
		free(strs[i].s);
	}
	free(strs);
	return 0;
}