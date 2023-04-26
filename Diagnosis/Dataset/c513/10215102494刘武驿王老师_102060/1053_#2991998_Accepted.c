#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *rstrstr(char *s1, char *s2)
{
  int  s1len = strlen(s1);
  int  s2len = strlen(s2);
  char *s;

  if (s2len > s1len)
    return NULL;
  for (s = s1 + s1len - s2len; s >= s1; --s)
    if (strncmp(s, s2, s2len) == 0)
      return s;
  return NULL;
}

int split(char *buf, char **dst) {
	int n = 0;
	char *pre = buf, *p = strpbrk(pre, ","), *end = buf + strlen(buf);
	while(p) {
		strncpy(*dst++, pre, p - pre);
		n++;
        pre = p + 1;
		p = strpbrk(pre, ",");
	}
    strncpy(*dst++, pre, end - pre);
	return n + 1;
}

char **allocate(int n, int m) {
	char **b = (char **)malloc(n * sizeof(char *));
	for(int i = 0; i < n; i++) {
		b[i] = (char *)malloc(m * sizeof(char));
        memset(b[i], 0, m);
	}
	return b;
}

void freen(char **p, int n) {
	for(int i = 0; i < n; i++)
		free(p[i]);
	free(p);
}


int validCode(const char *s) {
    char cc = 0;
    for(int i = 0, l = strlen(s); i < l; i++) {
        cc ^= s[i];
    }
    return cc;
}

int main()
{
    char **vt = NULL;
    char s[256], t[256];
    while ((scanf("%s", s)) && strcmp(s, "END") != 0) {
        char **dst = allocate(100, 100);
        strcpy(t, s);
        split(t, dst);
        if(strcmp(dst[2], "A") == 0) {
            char *start = rstrstr(s, "*");
            char sub[256] = {0};
            strncpy(sub, s + 1, start - s - 1);
            int vcode = validCode(sub);
            int code = strtol(dst[12] + 2, NULL, 16);
            if(code == vcode) {
                if(vt != NULL) {
                    freen(vt, 100);
                } 
                vt = dst;
            } else {
                freen(dst, 100);
            }
        }
    }
    int hh, mm, ss;
    sscanf(vt[1], "%2d%2d%2d", &hh, &mm, &ss);
    printf("%02d:%02d:%02d\n", (hh + 8) % 24, mm, ss);
    return 0;
}
