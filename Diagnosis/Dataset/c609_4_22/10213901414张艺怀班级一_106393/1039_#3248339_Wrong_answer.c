#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lbound(const char* s, const char* s1)
{
    int check = 0;
    int len_s = strlen(s), len_s1 = strlen(s1);
    if (len_s1 > len_s) return -1;
    else {
        for (int i = 0; i < len_s; i++) {
            if (s[i] == s1[0]) {
                int j = 1;
                for (; j < len_s1; j++) {
                    if (s[i + j] != s1[j]) {
                        check = 1;
                        break;
                    }
                }
                if (!check) return i;
                else {
                	i += j - 1;
					check = 0;	
				}
            }
        }
        return -1;
    }
}

int ubound(const char* s, const char* s1)
{
    int check = 0;
    int len_s = strlen(s), len_s1 = strlen(s1);
    if (len_s1 > len_s) return -1;
    else {
        for (int i = len_s-1; i >= 0; i--) {
            if (s[i] == s1[len_s1-1]) {
            	int j = len_s1-1;
                for (; j >= 1; j--) {
                    if (s[i - j] != s1[len_s1 - 1 - j]) {
                        check = 1;
                        break;
                    }
                }
                if (!check) return i-len_s1+1;
                else {
                	i -= j - 1;
					check = 0;	
				}
            }
        }
        return -1;
    }
}


int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
	    char s[100] = {0}, s1[100] = {0}, s2[100] = {0};
	    scanf("%s", s1);
	    scanf("%s", s2);
	    scanf("%s", s);
	    int left = lbound(s, s1), right = ubound(s, s2);
		printf("case #%d:\n", i);
		if (left != -1 && right != -1) {
			printf("%d\n", right - left - strlen(s1));
		}
		else {
			printf("0\n");
		}
	}

    return 0;
}
