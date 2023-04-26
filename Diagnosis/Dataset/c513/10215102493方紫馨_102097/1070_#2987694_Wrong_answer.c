#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	while(scanf("%d",&n)){
		if(n==-1)
			break;
		int num[20] = {0};
		num[3] = 1;num[4] = 4;
		
		printf("%d\n",(int)pow(2,n)-num[n]);
	}
	
	return 0;
}