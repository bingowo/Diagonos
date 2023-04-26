#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct{
	long long int x;
	int max;
}num;
long long int cmp(const void*a,const void *b){
	num p1=*(num*)a;
	num p2=*(num*)b;
	if(p1.max>p2.max) return -1;
	if(p1.max<p2.max) return 1;
	if(p1.max==p2.max) {
		if(p1.x>p2.x) return 1
		else return -1;
	}
}
int main(int argc, char *argv[]) {
	int T,N,k,i,j;
	long long int n,m;
	num a[10000];
	scanf("%d\n",&T);
	for(k=0;k<T;k++){
		scanf("%d\n",&N);
		printf("case #%d:\n",k);
		for(j=0;j<N;j++){
			scanf("%lld",&a[j].x);
			n=a[j].x;
			if(abs(n)>=10){
				while(abs(n)>=10){
					n=n/10;
					m=n;
				}
			}else m=abs(n);
			a[j].max=abs(m);
		}qsort(a,N,sizeof(a[0]),cmp);
		for(i=0;i<N-1;i++){
			printf("%lld ",a[i].x);
		}printf("%lld\n",a[i].x);
	}
	return 0;
}