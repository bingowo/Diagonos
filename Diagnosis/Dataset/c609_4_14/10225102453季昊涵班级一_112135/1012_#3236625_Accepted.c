#include <stdio.h>
#include <string.h>

int main() {
	int T;
	int k = 0;
	scanf("%d", &T);
	while (T--) {
		char oct[55], dec[155];
		scanf("%s", oct );
		int len = strlen(oct) - 1;
		int numbers = 0;
		int temp;
		for (; len != 1; --len) {
			int digit = oct[len] - '0';
			int j = 0;
			do {
				if (j < numbers)
					temp = digit * 10 + dec[j] - '0';
				else
					temp = digit * 10;
				dec[j++] = temp / 8 + '0';
				digit = temp % 8;
			} while (digit != 0 || j < numbers);
			numbers = j;
		}
		dec[numbers] = '\0';

		printf("case #%d:\n0.%s\n", k++, dec);
	}


	return 0;
}