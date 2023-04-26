#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char table[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int T;
	scanf("%d", &T);
	int i = 0;
	for (i = 0; i < T; i++) {
		int N, R;
		scanf("%d%d", &N, &R);
		while (N < 0) {
			N *= (-1);
			printf("-");
		}
		char ans[33];
		int num = 0;
		do {
			ans[num++] = N % R;
			N = N / R;
		} while (N != 0);

		int cout;
		for (num--; num >= 0; num--) {
			cout = ans[num];
			printf("%c", table[cout]);
		}
		printf("\n");
		i++;
	}


	return 0;
}