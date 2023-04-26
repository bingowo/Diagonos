#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		//printf("here");
		char num[1000];
		double ret=0;
		scanf("%s",num);
		for(int j=strlen(num)-1;j>1;j--){
			ret=ret/8+(int)num[j]-'0';
		}
		printf("case #%d:\n",i);
		printf("%f\n",ret/8);
	}
	return 0;
}