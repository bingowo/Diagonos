#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	  int num_a,num_b;
	num_a = *(  int *)a;
	num_b = *(  int *)b;
	  int count_a = 0,count_b = 0;
	while(num_a>0){
		if(num_a&1==1){
			count_a++;
		}
		num_a=num_a>>1;
	}
	while(num_b>0){
		if(num_b&1==1){
			count_b++;
		}
		num_b=num_b>>1;
	}
	if(count_a!=count_b){
		return count_b-count_a;
	}else{
		return *(  int*)a>*(  int*)b?1:-1;
	}
}


	

int main()
{  	int n,i,a[1000];  
	int k,j;
	scanf("%d",&k);
	for(j=0;j<k;j++){
		scanf("%d",&n);
	  	for (i=0;i<n;i++) 
		  	scanf("%d",a+i);  
	  	qsort(a,n,sizeof(  int),cmp);
	  	printf("case #%d:",j);
	  	for (i=0;i<n;i++) 
		  	printf("%d\n",a[i]);
	}	
  	return 0;
}