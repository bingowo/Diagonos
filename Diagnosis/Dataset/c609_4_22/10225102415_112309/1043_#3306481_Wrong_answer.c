#include <stdio.h>
#include <string.h>

int solve(char s[101]) {
	int len = strlen(s);
	int bracket[3] = {0}; //0：圆括号；1：方括号；2：花括号
	int state = -1;
	for (int j = 0; j < len; j++) {
		switch (state) {
			case 1:
				if (s[j] == '[') {
					bracket[1]++;
					state = 2;
				} else if (s[j] == '}') {
					if (bracket[2] > 0)
						bracket[2]--;
					else
						return 0;
					state = 3;
				} else
					return 0;
				break;
			case 2:
				if (s[j] == '(') {
					bracket[0]++;
					state = 3;
				} else if (s[j] == ']') {
					if (bracket[1] > 0)
						bracket[1]--;
					else
						return 0;
					state = 1;
				} else
					return 0;
				break;
			case 3:
				if (s[j] == '{') {
					bracket[2]++;
					state = 1;
				} else if (s[j] == ')') {
					if (bracket[0] > 0)
						bracket[0]--;
					else
						return 0;
					state = 2;
				} else
					return 0;
				break;
			default:
				if (s[j] == '(') {
					bracket[0]++;
					state = 3;
				} else if (s[j] == '[') {
					bracket[1]++;
					state = 2;
				} else if (s[j] == '{') {
					bracket[2]++;
					state = 1;
				} else {
					return 0;
				}
				break;
		}
		if (bracket[0] + bracket[1] + bracket[2] == 0)
			state = -1;
		printf("[%d, %d, %d] ", bracket[0], bracket[1], bracket[2]);
		printf("%d\n", state);
	}
	for (int k = 0; k < 3; k++) {
		//printf("%d ", bracket[k]);
		if (bracket[k] > 0)
			return 0;
	}
	return 1;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		char s[101];
		scanf("%s", s);
		if (solve(s))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}