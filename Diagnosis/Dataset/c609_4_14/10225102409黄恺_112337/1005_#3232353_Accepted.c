#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int T;
	scanf("%d",&T) ;
	int i = 0;
	while(i<T) {
		char ans[100];
		scanf("%s",ans);
		int l = strlen(ans);
		l--;
		int sum = 0;
		int temp = 1;
		while(l>=0) {
			if (ans[l] == '1') {
				sum += temp;
			} else if (ans[l] == '-') {
				sum -= temp;
			}
			temp *= 3;
			l--;
		}
		printf("case #%d:\n%d\n",i,sum);
		i++;
	}
    return 0;
}
