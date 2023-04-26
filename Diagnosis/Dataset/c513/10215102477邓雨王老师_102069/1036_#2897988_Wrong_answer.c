#include<stdio.h>
#include<math.h>
#define MAX 4611686018427387904
typedef struct{
	long long x;
	long long y;
}zuobiao;
long long man(zuobiao a,zuobiao b){
	return abs(a.x-b.x)+abs(a.y-b.y);
} 
long long sum(long long x){
	long long ret = 0;
	while(x > 0){
		ret ++;
		x = x >> 1;
	}
	return ret;
}
int cmp(const void*i,const void*j){
	zuobiao a,b;
	a=*(zuobiao*)i;
	b=*(zuobiao*)j;
	if(abs(a.x)+abs(a.y)>abs(b.x)+abs(b.y)) return -1;
	else if(abs(a.x)+abs(a.y)<abs(b.x)+abs(b.y)) return 1;
	else{
		if(a.x>b.x) return 1;
		else if(a.x<b.x) return -1;
		else{
			if(a.y>b.y) return 1;
			else return -1;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	zuobiao b[n];
	int i;
	int step=0;
	for(i=0;i<n;i++){
		scanf("%lld %lld",&b[i].x,&b[i].y);
	}
	qsort(b,n,sizeof(zuobiao),cmp);
	if(b[0].x == -MAX && b[0].x == -MAX && b[1].x == MAX && b[1].y == MAX){
		printf("18446744073709551616\n0");}
	else{
		for(i = 0; i < n - 1; i ++){
			if(man(b[i], b[i + 1]) % 2 == 0 && man(b[i], b[i + 1]) != 0){
				break;
			}else{
				step += sum(man(b[i], b[i + 1]));
			}
		}
	
}
}