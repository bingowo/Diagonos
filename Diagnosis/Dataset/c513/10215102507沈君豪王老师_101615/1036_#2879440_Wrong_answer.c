#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int lli;
typedef unsigned long long int llu;
typedef struct{
	lli x, y;
	llu length;
}Point;

lli llabs(lli x){ return x < 0 ? -x : x;}

llu distance(Point *a, Point *b)
{
	llu ret;
	ret = llabs(a->x - b->x) + llabs(a->y - b->y);
	return ret;
}

llu CountTwo(llu x)
{
	llu ret = 0;
	while(x > 0){
		ret ++;
		x = x >> 1;
	}
	return ret;
	
}

int cmp(const void *a, const void *b)
{
	Point * pa = (Point *)a;
	Point * pb = (Point *)b;
	if(pa->length != pb->length){
		return pa->length < pb->length ? 1 : -1;
	}else if(pa->x != pb->x){
		return pa->x > pb->x ? 1 : -1;
	}else{
		return pa->y > pb->y ? 1 : -1;
	}
}



int main(void)
{
	int n;
	scanf("%d", &n);
	llu step = 0;
	Point in[n];
	for(int i = 0 ; i < n; i ++){
		scanf("%lld %lld", &in[i].x, &in[i].y);
		in[i].length = llabs(in[i].x) + llabs(in[i].y);
	}
	qsort(in, n, sizeof(Point), cmp);
	for(int i = 0; i < n - 1; i ++){
		if(distance(&in[i], &in[i + 1]) % 2 == 0 && distance(&in[i], &in[i + 1]) != 0){
			break;
		}else{
			step += CountTwo(distance(&in[i], &in[i + 1]));
		}
	}
	printf("%llu\n", distance(&in[0], &in[1]));
	printf("%llu", step);
	
	return 0;
}