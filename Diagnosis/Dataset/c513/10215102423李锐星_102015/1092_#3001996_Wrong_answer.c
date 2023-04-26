#include <stdio.h>
#include <string.h>

int main()
{
	char w[1001];
	int num[1001];
	int i;
	for (i=0;i<1001;i++){
		num[i]=0;
	}
	scanf("%s",w);
	for (i=0;i<strlen(w);i++){
		if(i==0){
			if(strlen(w)==1){
				num[i]=1;
			}
			else if(w[i]==w[i+1]){
				num[i]=1;
			}
			else{
				num[i]=2;
			}
		}
		else if(i==strlen(w)-1){
			if(w[i]==w[i-1]){
				num[i]=1;
			}
			else{
				num[i]=2;
			}
		}
		else{
			if(w[i]==w[i-1]&&w[i]==w[i+1]){
				num[i]=1;
			}
			else if(w[i]==w[i-1]&&w[i]!=w[i+1]){
				num[i]=2;
			}
			else if(w[i]!=w[i-1]&&w[i]==w[i+1]){
				num[i]=2;
			}
			else{
				num[i]=3;
			}
		}
	}
	for (i=0;i<1001;i++){
		if(num[i]!=0){
			printf("%d ",num[i]);
		}
		else{
			break;
		}
	}
	printf("\n");
	int result[500];
	for (i=0;i<500;i++){
		result[i]=-1;
	}
	result[0]=num[0];
	for (i=1;i<strlen(w);i++){
		int x=0;
		int j;
		for (j=0;result[j]!=-1;j++){
			x=result[j]*num[i]+x;
			result[j]=x%10;
			x/=10;
		}
		if(x!=0){
			result[j]=x;
		}
	}
	for (i=499;i>-1;i--){
		if(result[i]!=-1){
			printf("%d",result[i]);
		}
	}
	printf("\n");
	return 0;
}