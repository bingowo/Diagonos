#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int T;
	scanf("%d", &T);
	int k = 0;
	while (T--) {
		char in[11];
		char st[100];
		double db[3];
		int s = 0;
		int d = 0;
		while ((scanf("%s", &in)) != EOF) {
			if (isdigit(in[0])) {
				db[d++] = atof(in);
			} else {
				char c = in[0];
				st[s++] = c;
			}
			if (d == 2) {
				double temp1 = db[0];
				double temp2 = db[1];
				s--;
				if (st[s] == '+')
					db[0] = temp1 + temp2;
				else if (st[s] == '*')
					db[0] = temp1 * temp2;
				else if (st[s] == '/')
					db[0] = temp1 / temp2;
				else if (st[s] == '-')
					db[0] = temp1 - temp2;
				d = 1;
			}
			char c = getchar();
			if (c == '\n')
				break;
		}
		printf("case #%d:\n", k++);
		printf("%.6lf\n", db[0]);

	}

	return 0;
}