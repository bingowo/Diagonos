#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	int num_a,num_b;
	num_a = *(int *)a;
	num_b = *(int *)b;
	int count_a = 0,count_b = 0,t;
	int d=1;
	for(t=0;t<64;t++){
		//printf("here");
		if(num_a&d==1){
			count_a+=1;
		}
		if(num_b&d==1){
			count_b+=1;
		}
		d=d<<1;
	}
	//printf("%d %d\n",count_a,count_b);	
	return count_b-count_a;
	
}


	

int main()
{  	int n,i;  
	int k,j;
	long long a[1000];
	scanf("%d",&k);
	for(j=0;j<k;j++){
		scanf("%d",&n);
	  	for (i=0;i<n;i++) 
		  	scanf("%lld",a+i);  
	  	qsort(a,n,sizeof(a[0]),cmp);
	  	printf("case #%d:\n",j);
	  	for (i=0;i<n;i++) 
		  	printf("%lld ",a[i]);
		printf("\n");
	}	
  	return 0;
}