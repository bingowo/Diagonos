#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int i, T;
	scanf("%d",&T);
	for (i = 0; i < T; i++){
		char s[100];
		scanf("%s",s);
		int len = strlen(s);

		int j;
		int ans = 0;
		for (j = 0; j < len; j++){
			int digit = len - j - 1;
			int a;
			switch(s[j]){
				case '1':a = 1;	break;
				case '-':a = -1;break;
				case '0':a = 0; break;
			}
			ans += + a * pow(3,digit);
		}

		printf("case #%d:\n",i);
		printf("%d\n",ans);
	}
	return 0;
}