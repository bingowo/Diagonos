#include <stdio.h>
#include <stdlib.h>

int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int oprPtr = 0;
		int opr[40] = {0}; // 0:default 1:+ 2:- 3:* 4:/ 
		int numPtr = 0;
		double num[80];
		int type[110] = {0}; // 0:default 1:double num 2: operator
		int typePtr = 0;
		
		char c, inp[40];
		scanf("%s", &inp);
		opr[oprPtr++] = inp[0];
		type[typePtr++] = 2;
		while ((c = getchar()) != '\n') {
			scanf("%s", &inp);
			if (inp[0] >= '0' && inp[0] <= '9') {
				num[numPtr++] = atof(inp);
				type[typePtr++] = 1;
			}
			else {
				opr[oprPtr++] = inp[0];
				type[typePtr++] = 2;
			}
		}
		
//		for (int j = 0; j < oprPtr; j++) {
//			printf("%c ", opr[j]); 
//		}
//		printf("\n");
//		for (int j = 0; j < numPtr; j++) {
//			printf("%lf ", num[j]); 
//		}
//		printf("\n");
//		for (int j = 0; j < typePtr; j++) {
//			printf("%d ", type[j]);
//		}
//		printf("Have read.\n\n");
		
		for (int j = typePtr-1; j > -1; j--) {
			if (type[j] == 2) {
				if(opr[oprPtr-1] == '+') {
					num[numPtr-2] = num[numPtr-2] + num[numPtr-1];
					num[numPtr-1] = 0;
					numPtr--;
				} else if(opr[oprPtr-1] == '-') {
					num[numPtr-2] = num[numPtr-2] - num[numPtr-1];
					num[numPtr-1] = 0;
					numPtr--;
				} else if(opr[oprPtr-1] == '*') {
					num[numPtr-2] = num[numPtr-2] * num[numPtr-1];
					num[numPtr-1] = 0;
					numPtr--;
				} else if(opr[oprPtr-1] == '/') {
					num[numPtr-2] = num[numPtr-2] / num[numPtr-1];
					num[numPtr-1] = 0;
					numPtr--;
				} else {
					printf("Error!\n");
				}
				oprPtr--;
//				printf("Current oprater: %c[%d]\n", opr[oprPtr], oprPtr);
//				for (int j = 0; j < numPtr; j++) {
//					printf("%lf ", num[j]); 
//				}
//				printf("\n");
			}
		}
		printf("%lf\n", num[0]);
	}
	return 0;
}