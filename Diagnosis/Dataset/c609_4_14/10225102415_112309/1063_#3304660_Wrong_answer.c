#include <stdio.h>

int hash[50] = {0};

int solve(int target) {
	if (target <= 1) return 1;
	else if (target == 2) return 2;
	else if (target == 3) return 4;
	else if (target == 4) return 8;
	if (hash[target] != 0) return hash[target];
	else {
		hash[target] = solve(target-1) + solve(target-2) + solve(target-3) + solve(target-4);
		return hash[target];
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int target;
		scanf("%d", &target);
		printf("case #%d:\n%d\n", i, solve(target));
	}
}