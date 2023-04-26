#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct num{
	long long int x;
	int count;
};
int cmp(const void*a, const void*b){
	struct num x,y;
	x=*(struct num*)a,y=*(struct num*)b;
	if(x.count==y.count){
		if(x.x>y.x)return 1;
		else return -1;
	} 
	else {
		if(x.count>y.count)return -1;
		else return 1;
	}
}  //快速排序 
int main(int argc, char *argv[]) {
    int t,n,k,i,j;
    long long int y;
    struct num a[10000];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%lld",&y);  //输入需要排序的数字
			a[j].x=y;a[j].count=0;
			for(k=0;k<64;k++){
				if(y&(1LL<<k))a[j].count++;
			}  //计算1的个数 
		}
		qsort(a,n,sizeof(a[0]),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<n;j++){
			printf("%lld ",a[j].x);
		}
		printf("\n");
	} 
	return 0;
}