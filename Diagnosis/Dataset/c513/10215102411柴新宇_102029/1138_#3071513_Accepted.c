#include <stdio.h>
#include <string.h>


char a[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int changeA(int a, char in[]) {
	int y = 0;
	int len = strlen(in);
	for (int i = 0; i < len; i++) {
		y *= a;
		if (in[i] >= '0' && in[i] <= '9') {
			//	printf("0-9\n");
			y += (in[i] - '0');
			//	printf("0-9,,y=%d\n", y);
		}

		else if (in[i] >= 'a' && in[i] <= 'z') {
			//printf("a-z\n");
			y += (in[i] - 'a' + 10);
			//printf("a-z,,y=%d\n", y);
		}

		else {
			//printf("A-Z\n");
			y += (in[i] - 'A' + 10) ;
			//printf("A-Z,,y=%d\n", y);

		}
	}
//	printf("y=%d\n", y);
	return y;
}

int changeB(int y, int b) {
	int z[40], num = 0;
	do {
		z[num++] = y % b;
		y = y / b;
	} while (y != 0);
	char a[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	for (int i = num - 1; i >= 0; i--) {
		printf("%c", a[z[i]]);
	}

}



int main() {
	int changeA(int a, char in[]);
	int changeB(int y, int b);
	int a, b;
	char in[101];
	scanf("%d%s%d", &a, in, &b);
	int c;
	c = changeA(a, in);
	changeB(c, b);

	return 0;
}