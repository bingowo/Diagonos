#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
	int T,n1,n2,n,sum;
	scanf("%d",&T);
	while(T--){
		sum=0;
		scanf("%d%d",&n1,&n2);
		n=n1^n2;
		while(n!=0)
		{
			if(n%2) sum++;
			n/=2;
		}
		printf("%d\n",sum);
	}	
	return 0;
}

