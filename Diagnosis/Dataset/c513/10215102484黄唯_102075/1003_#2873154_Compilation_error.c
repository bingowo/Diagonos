#include<stdio.h>

typedef long long int lli;
int i;
int countone(lli x){
	int sum=0;
	int ret=1;
	for(i=0;i<64;i++){
		if(x&1){
		sum++;
	    }
		ret=ret<<1;
	}
	return sum;
	
}
int cmp(const void*a,const void *b){
	lli oa=countone*(lli*)a;
	lli ob=countone*(lli*)b;
	if(oa!=ob)
	return *(lli*)b)-*(lli*)a;
	else
	return oa>ob?1:-1;
}


 int main(){
 	int t,j;
 	scanf("%d",&t);
 	for(int i = 0 ; i < t; i ++){
        int n;
        scanf("%d", &n);
        lli num[n];
        for(int j = 0 ; j < n ; j ++){
            scanf("%lld", &num[j]);
        }
        qsort(num, n, sizeof(lli), cmp);
        printf("case #%d:\n", i);
        for(int j = 0 ; j < n; j ++){
            printf("%lld%c", num[j], j == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
 	
 } 