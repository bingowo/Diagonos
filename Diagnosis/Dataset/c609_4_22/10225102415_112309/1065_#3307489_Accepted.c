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
		
		int numSize = numPtr;
		for (int j = typePtr-1; j > -1; j--) {
			if (type[j] == 1) {
				numPtr--;
			} 
			if (type[j] == 2) {
//				printf("%lf %c[%d] %lf\n",num[numPtr], opr[oprPtr-1], oprPtr, num[numPtr+1]);
				if(opr[oprPtr-1] == '+') {
					num[numPtr+1] = num[numPtr] + num[numPtr+1];
					for (int k = numPtr; k > 0; k--) num[k] = num[k-1];
					num[0] = 0; 
				} else if(opr[oprPtr-1] == '-') {
					num[numPtr+1] = num[numPtr] - num[numPtr+1];
					for (int k = numPtr; k > 0; k--) num[k] = num[k-1];
					num[0] = 0; 
				} else if(opr[oprPtr-1] == '*') {
					num[numPtr+1] = num[numPtr] * num[numPtr+1];
					for (int k = numPtr; k > 0; k--) num[k] = num[k-1];
					num[0] = 0; 
				} else if(opr[oprPtr-1] == '/') {
					num[numPtr+1] = num[numPtr] / num[numPtr+1];
					for (int k = numPtr; k > 0; k--) num[k] = num[k-1];
					num[0] = 0; 
				} else {
					printf("Error!\n");
				}
				oprPtr--;
				numPtr++;
//				for (int j = 0; j < numSize; j++) {
//					printf("%lf ", num[j]); 
//				}
//				printf("\n");
			}
		}
		printf("case #%d:\n%lf\n", i, num[numPtr]);
	}
	return 0;
}