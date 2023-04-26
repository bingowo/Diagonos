#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a, b) (a > b? a: b)

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

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) {
        char a[256], b[256], s[256];
        scanf("%s%s%s", a, b, s);
        char *ia = strstr(s, a), *ira = rstrstr(s, a);
        char *ib = strstr(s, b), *irb = rstrstr(s, b);
        int la = strlen(a), lb = strlen(b);
        int r = 0;
        if(ia != NULL && ib != NULL)
            r = max((int)(irb - ia - la), (int)(ira - ib - lb));
        printf("case #%d:\n%d\n", i,  max(r, 0));
    }
    
	return 0;
}