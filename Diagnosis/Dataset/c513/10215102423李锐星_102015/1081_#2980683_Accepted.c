#include <stdio.h>

void solve(int T)
{
	int result[200];
	for (int i=0;i<200;i++){
		result[i]=-1;
	}
	int a,n;
	scanf("%d %d",&a,&n);
	if(n==0){
		printf("1\n");
	}
	else{
		result[0]=a;
		for(int i=1;i<n;i++){
			int num=0;
			int j;
			for (j=0;result[j]!=-1;j++){
				num=result[j]*a+num;
				result[j]=num%10;
				num=num/10;
			}
			if(num!=0){
				result[j]=num;	
			}
		}
		for (int i=199;i>-1;i--){
			if(result[i]!=-1){
				printf("%d",result[i]);
			}
		}
		printf("\n");
	}
	
	
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
}