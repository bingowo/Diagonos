#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		printf("case #%d:\n",v);
		int m=1,n=1,large=1,small=1,i=1; 
		unsigned long long P=1; 
		scanf("%d%d", &m, &n);
		if (m>2*n) {small=n; large=m-n;}
        else {small=m-n; large=n;}
        //
		for(i = m; i > large; i--){
        if (i==2*small)     {
		P=P*2; 
		small--;            }
        else P = P*i;             }
        while (small>1){
         P=P/small;
		 small--;	 
	}
	printf("%llu\n", P);
}
return 0;
}	