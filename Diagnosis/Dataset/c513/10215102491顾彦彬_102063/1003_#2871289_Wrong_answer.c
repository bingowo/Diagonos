#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a, const void*b) {
	int countx = 0, county = 0;
	long long int x = *(long long int*)a;
	long long int y = *(long long int*)b;
	for (int i=0;i<64;i++)
		if(((unsigned long long)x<<(63-i)>>63)==1) countx++;
	for (int i=0;i<64;i++)
		if(((unsigned long long)x<<(63-i)>>63)==1) county++;
	x = *(long long int*)a;
	y = *(long long int*)b;
	if (countx == county){
		if (x>=y)
			return 1;
		if (x<y)
			return -1;
	}
	else
		return county - countx; 	
}
int main() {
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