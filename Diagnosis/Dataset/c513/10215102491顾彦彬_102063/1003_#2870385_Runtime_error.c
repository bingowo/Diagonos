#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a, const void*b) {
	int m[100], n[100], countx = 0, county = 0;
	int x = *(int*)a;
	int y = *(int*)b;
	int i = 0, j = 0;
	do {
		m[i] = x % 2;
		x = x / 2;
		i += 1;
	} while (x);
	do {
		n[j] = y % 2;
		y = y / 2;
		j += 1;
	} while (y);
	for (int p = 0; p < sizeof(m); p++) {
		if (m[p] == 1)
			countx += 1;
	}
	for (int p = 0; p < sizeof(n); p++) {
		if (n[p] == 1)
			county += 1;
	}
	if (countx == county)
		return *(int*)a - *(int*)b;
	else
		return countx - county;
}
main() {
		int T,t=0;
		scanf("%d",&T); 
		while(T--){
			int nums;
			scanf("%d",&nums);
			int input[10000];
			for (int i=0;i<nums;i++)
				scanf("%d",&input[i]);
			qsort(input,nums,sizeof(input),cmp);
			printf("case #%d:\n",t=0);
			for(int i=0;i<nums;i++)
            	printf("%lld ",input[i]);
	        printf("\n");
	        t++;
		}
}