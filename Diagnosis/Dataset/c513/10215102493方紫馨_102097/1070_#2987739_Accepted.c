#include<stdio.h>
#include<math.h>

int main()
{
	int n,num[21];
	num[0] = 1,num[1] = 2,num[2] = 4,num[3] = 7;
	for(int i=4;i<21;i++){
		num[i] = num[i-1]*2;
		int sign = -1;
		for(int j=i-3;j>=0;j-=2){
			num[i] += sign * num[j];
			sign *= -1;
		}
	} 	
	scanf("%d", &n);
	while(n != -1){
		printf("%d\n", num[n]);
		scanf("%d", &n);
	}
	
	return 0;
}