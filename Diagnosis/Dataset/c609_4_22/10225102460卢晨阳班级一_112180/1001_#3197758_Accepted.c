#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n,r;
		char a[100]={0};
		int cnt=0;
		scanf("%d %d",&n,&r);
		if(n<0){
			n=-n;
			printf("-");
		}
		while(n!=0){
			if(n/r>9){
				a[cnt]=n%r;
				n=n/r;
				cnt++;
			}else{
				a[cnt]=n%r;
				n=n/r;
				cnt++;
			}	
		}
		for(int j=cnt-1;j>=0;j--){
			if(a[j]<10)
			printf("%d",a[j]);
			else
			printf("%c",55+a[j]);
		}
		
		printf("\n");
	}
	return 0;
 } 