#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;
typedef struct{
	lli r;
	lli h;
	lli SuperficialArea;
	lli BaseArea;
	lli LateralArae;
	int id; 
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
		input[i].id = i;
		if(input[i].SuperficialArea >  MaxSuperficialArea){
			 MaxSuperficialArea = input[i].SuperficialArea;
			 Maxid = input[i].id;
		}
	}
	qsort(input, n, sizeof(Cylinder), cmp);
	for(int i = 0 ; i < m - 1; i ++){
		if(input[i].id != Maxid){
			MaxArea += input[i].LateralArae;
		}else{
			m += 1;
		}
	}
	MaxArea += MaxSuperficialArea;
	printf("%lld", MaxArea);
	
	return 0;
}