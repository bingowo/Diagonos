#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a,const void* b){
	  int num_a,num_b;
		num_a = *(  int *)a;
		num_b = *(  int *)b;
	  int count_a = 0,count_b = 0,t;
	for(t=0;t<64;t++){
		if(num_a&1==1){
			count_a++;
		}
		num_a=num_a>>1;
	}
	for(t=0;t<64;t++){
		if(num_b&1==1){
			count_b++;
		}
		num_b=num_b>>1;
	}
	//printf("%d %d\n",count_a,count_b);
	return count_b-count_a;
	
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
	  	printf("case #%d:\n",j);
	  	for (i=0;i<n;i++) 
		  	printf("%d ",a[i]);
		printf("\n");
	}	
  	return 0;
}