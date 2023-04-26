#include <stdio.h>
#include <string.h>

int main() {
	int rome[128];
	rome['I'] = 1;
	rome['V'] = 5;
	rome['X'] = 10;
	rome['L'] = 50;
	rome['C'] = 100;
	rome['D'] = 500;
	rome['M'] = 1000;
	char num[50];
	scanf("%s", num);

	long long stack[100];
	long long int ans = 0;
	long long int blank = 0;
	int cnt = 0;

	for (int i = 0; i < strlen(num); i++) {
		switch (num[i]) {
			case '(':
				blank++;
				break;
			case ')':
				break;
			default:
				stack[cnt++] = rome[num[i]];
				break;
		}
	}

	for (int i = 0; i < cnt; i++) {
		if (stack[i] < stack[i + 1] && i != cnt - 1)
			ans -= stack[i];
		else
			ans += stack[i];
	}

	for (int i = 0; i < blank; i++) {
		ans *= 1000;
	}
	printf("%lld", ans);

	return 0;
}

