#include<stdio.h>
int binary(int n,char a[]){
	int i=0;
	while(n>0){
		if(n%2==1)
			a[i]=1;
		else
			a[i]=0;
		n/=2;
		i++;
	}
	return i;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int n;
		scanf("%d",&n);
		char a[32];
		int k=binary(n,a);
		int max=0,cnt=1;
		for(int i=1;i<k;i++){
			if(a[i]!=a[i-1]){
				cnt++;
			}else{
				if(max<cnt)
					max=cnt;
				cnt=1;
			}			
		}
		if(max<cnt)
			max=cnt;
		printf("case #%d:\n",i);
		printf("%d\n",max);
	}
	return 0;
}