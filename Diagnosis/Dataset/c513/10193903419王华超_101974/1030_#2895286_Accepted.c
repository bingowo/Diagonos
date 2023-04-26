#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
 
int cmp(const void *p1,const void *p2){
	long long int a=*((long long int*)p1),b=*((long long int*)p2);
	long long int aj=fabs(a),bj=fabs(b);
	while(aj>=10){
		aj=aj/10;
	}
	while(bj>=10){
		bj=bj/10;
	}
	if(aj!=bj){
		return bj-aj;
	}
	else{
		if(a>b) return 1;
		else return -1;
	}
	
}
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int i=0;i<cas;i++){
		int n;
		scanf("%d",&n);
		long long int *s;
		s=(long long int *)malloc(n*sizeof(long long int));
		for(int j=0;j<n;j++){
			scanf("%lld",&s[j]);
		}
		qsort(s,n,sizeof(s[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++){
			printf("%lld ",s[j]);
		}
		printf("\n");
		free(s);
	}
	return 0;
}