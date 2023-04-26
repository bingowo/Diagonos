#include <stdio.h>
#include <malloc.h>

int main()
{
	int k,n;
	scanf("%d%d",&k,&n);
	if(n==1){
		printf("0\n");
	}
	else{
		int *a;
		a=(int*)malloc(n*sizeof(int));
		a[0]=0;
		a[1]=1;
		for (int i=2;i<n;i++){
			int num=0;
			if(i<k){
				for (int j=i-1;j>-1;j--){
					num+=a[j];
				}
			}
			else{
				for (int j=i-1;j>i-k-1;j--){
					num+=a[j];
				}
			}
			a[i]=num;
		}
		printf("%d\n",a[n-1]);
	}
	return 0;
}