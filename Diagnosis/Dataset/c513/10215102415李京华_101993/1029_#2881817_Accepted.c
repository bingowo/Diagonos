#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int ncase, T;
	scanf("%d\n", &ncase);
	for (T = 0; T < ncase; T++) {

		char s[201];
		gets(s);

		//排序
		int i, j;
		for (i = 0; i < strlen(s) - 1; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z')
				for (j = i + 1; j < strlen(s); j++){
					if (s[j] >= 'A' && s[j] <= 'Z'){
						if (s[j] < s[i]){
							char swap = s[i];
							s[i] = s[j];
							s[j] = swap;
						}
					}
				}

		}

		//输出
		printf("case #%d:\n", T);
		printf("%s\n", s);
	}
	return 0;
}