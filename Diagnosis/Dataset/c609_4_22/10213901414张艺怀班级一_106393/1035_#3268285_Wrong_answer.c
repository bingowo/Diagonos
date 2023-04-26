#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(const char* s, int len)
{
    for (int i = 0; i < len-1; i++) {
        if (s[i+1] == s[i]) return 1; // 1 for check false
    }
    return 0;
}

int cnt_zero(const char* s, int len)
{
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'd') cnt++;
    }
    return cnt;
}

int clear(const char* s)
{
    int len_origin = strlen(s), len = len_origin;
    char s1[120] = {0};
    strcpy(s1, s);
    while (check(s1, len)) {
        for (int i = 0; i < len-1; i++) {
            if (s1[i+1] == s1[i]) {
            	int j = i+1;
                for (; j < len && s1[j] == s1[i]; j++);
                memmove(&s1[i], &s1[j], (len - j) * sizeof(char));
                len -= (j-i);
                i -= j-i-1;
                s1[len] = 0;
            }
        }
    }
    return len_origin - len;
}

int process(const char* s)
{
    int len = strlen(s), max = -1;
    char s1[120] = {0};
    strcpy(s1, s);
    int check = 0;
	for (int i = 1; i < len; i++) {
        if (s1[i-1] != s1[i] && s1[i] != s1[i+1]) {
            memmove(&s1[i+1], &s[i], (len-i) * sizeof(char));
            s1[i] = s1[i+1];
            int temp = clear(s1);
            max = (temp > max) ? temp : max;
            memset(s1, 0, 120 * sizeof(char));
            strcpy(s1, s);
            check = 1;
        }
    }
    if (!check) {
		max = clear(s) + 1;	
	}
    return max;
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    char s[120] = {0};
    for (int i = 0; i < T; i++) {
        scanf("%s", s);
        int max = process(s);
        printf("case #%d:\n%d\n", i, max);
    }
    return 0;
}
