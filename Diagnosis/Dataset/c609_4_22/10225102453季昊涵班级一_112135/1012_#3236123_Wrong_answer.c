#include <stdio.h>
#include <string.h>

int main() {
	int T;
	int k = 0;
	scanf("%d", &T);
	while (T--) {
		char in[1002];
		scanf("%s", in);
		int len = strlen(in);
		double out = 0;
		for (int i = len - 1; i > 0; i--) {
			if (in[i] == '.') {
				out = out * 0.125;
				break;
			}
			out = out * (0.125) + in[i] - '0';
		}
		printf("case #%d:\n%lf\n", k++, out);
	}


	return 0;
}