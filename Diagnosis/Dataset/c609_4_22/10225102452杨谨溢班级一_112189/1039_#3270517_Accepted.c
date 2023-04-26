# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		char s1[84], s2[84], s[84];
		scanf("%s\n%s\n%s", s1, s2, s);
		int lens = strlen(s);
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		int loc11 = -1, loc12 = -1, loc21 = -1, loc22 = -1;
		char* sp = s;
		for (int i = 0; i <= lens - len1; ++i)  // ab
		{
			if ((strncmp(sp + i, s1, len1)) == 0)  loc11 = i + len1;
			if (loc11 >= 0)  break;
		}
		sp = s;
		for (int i = 0; i <= lens - len2; ++i)
		{
			if ((strncmp(sp + i, s2, len2)) == 0)  loc21 = i + len2;
			if (loc21 >= 0)  break;
		}
		sp = s;
		for (int i = lens - len1; i >= 0; --i)
		{
			if ((strncmp(sp + i, s1, len1)) == 0)  loc12 = i;
			if (loc12 >= 0)  break;
		}
		sp = s;
		for (int i = lens - len2; i >= 0; --i)
		{
			if ((strncmp(sp + i, s2, len2)) == 0)  loc22 = i;
			if (loc22 >= 0)  break;
		}
		int m1 = loc22 - loc11;
		int m2 = loc12 - loc21;
//printf("%d %d %d %d %d %d\n", loc11, loc21, loc12, loc22,m1,m2);
		printf("case #%d:\n", t);
		if (((loc22 >= 0 && loc11 >= 0) || (loc12 >= 0 && loc21 >= 0)) && (m1 > 0 || m2>0 )) printf("%d\n", m1 > m2 ? m1 : m2);
		else printf("0\n");
	}
	return 0;
}