#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a, const void*b) {
	long long int m[10001], n[10001];
	int countx = 0, county = 0;
	long long int x = *(long long int*)a;
	long long int y = *(long long int*)b;
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
	for (int p = 0;m[p]!='\n'; p++) {
		if ((m[p] == 1)||(m[p]==-1))
			countx += 1;
	}
	for (int p = 0;n[p]!='\n'; p++) {
		if ((n[p] == 1)||(n[p]==-1))
			county += 1;
	}
	if (countx == county){
		if (x>=y)
			return 1;
		if (x<y)
			return -1;
	}
	else
		return countx - county; 	
}
int main() {
		int p;
		p=-3;
		p=p%2;
		printf("%d",p);
		int T,t=0;
		scanf("%d",&T); 
		for (int j=0;j<T;j++){
			int nums;
			scanf("%d",&nums);
			long long int input[10001];
			for (int i=0;i<nums;i++)
				scanf("%lld",&input[i]);
			qsort(input,nums,sizeof(input[0]),cmp);
			printf("case #%d:\n",t);
			for(int i=0;i<nums;i++)
            	printf("%lld ",input[i]);
	        printf("\n");
	        t++;
		}
	return 0;
}