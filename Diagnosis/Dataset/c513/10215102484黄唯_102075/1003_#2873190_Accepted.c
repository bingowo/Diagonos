#include<stdio.h>
#include <stdlib.h>
typedef long long int lli;

int countone(lli x){
	int sum=0;
	int ret=1;
	int i;
	for( i=0;i<64;i++){
		if(x&ret){
		sum++;
	    }
		x=x>>1;
	}
	return sum;
	
}
int cmp(const void*a,const void *b){
	lli a1=*(lli*)a;
	lli b1=*(lli*)b;
	lli oa=countone(a1);
	lli ob=countone(b1);
	if(oa!=ob)
	return ob-oa;
	else
	return a1>b1?1:-1;
}


 int main(){
 	int t,j,i;
 	scanf("%d",&t);
 	for( i = 0 ; i < t; i ++){
        int n;
        scanf("%d", &n);
        lli num[n];
        for( j = 0 ; j < n ; j ++){
            scanf("%lld", &num[j]);
        }
        qsort(num, n, sizeof(lli), cmp);
        printf("case #%d:\n", i);
        for( j = 0 ; j < n; j ++){
            printf("%lld%c", num[j], j == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
 	
 