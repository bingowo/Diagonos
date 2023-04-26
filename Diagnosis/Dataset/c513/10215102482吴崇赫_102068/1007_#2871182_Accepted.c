#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(void) {
	int m;
	int i=0;
	scanf("%d",&m);
	while(m--) {
		int val=0;
		int n;
		scanf("%d",&n);
		int temp=0;
		while(n) {
			if(n!=1 && n/2%2 != n%2)
				val++;
			else {
				val=0;
			}
			n=n/2;
			if(temp<=val)
				temp=val+1;
			//printf("val %d temp%d\n",val,temp);
		}
		printf("case #%d:\n%d\n",i++,temp);
	}
	return 0;
}