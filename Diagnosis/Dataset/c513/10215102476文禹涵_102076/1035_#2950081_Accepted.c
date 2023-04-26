#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;
typedef struct{
	lli r;
	lli h;
	lli SuperficialArea;
	lli BaseArea;
	lli LateralArae;
}Cylinder;

int cmp(const void *a, const void *b)
{
	Cylinder *pa = (Cylinder *)a;
	Cylinder *pb = (Cylinder *)b;
	return pb->LateralArae > pa->LateralArae ? 1 : -1;
}

int main(void)
{
	int n, m, Maxid;
	lli MaxArea = 0, MaxSuperficialArea = 0;
	scanf("%d %d", &n, &m);
	Cylinder input[n];
	for(int i = 0 ; i < n; i ++){
		scanf("%lld %lld", &input[i].r, &input[i].h);
		input[i].BaseArea = input[i].r * input[i].r;
		input[i].LateralArae = 2 * input[i].r * input[i].h;
		input[i].SuperficialArea = input[i].BaseArea + input[i].LateralArae;
	}
	qsort(input, n, sizeof(Cylinder), cmp);
	for(int i = 0 ;i < n; i ++){
		int choice = 1;
		lli area = input[i].SuperficialArea;
		for(int j = 0 ; j < n && choice < m; j ++){
			if(i == j || input[j].r > input[i].r){
			continue;
			}
			area += input[j].LateralArae;
			choice ++;
		}
		if(choice == m){
			MaxArea = area > MaxArea ? area : MaxArea;
		}
	}
	MaxArea += MaxSuperficialArea;
	printf("%lld", MaxArea);
	
	return 0;
}
