#include<stdio.h>
#include<stdlib.h>
int GCD(int y,int x){
	int t=1;
	while(t!=0){
		t=x%y;
		x=y;
		y=t;
	}
	return x;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){		
		int N,num[1000],sign[1001]={0};
		scanf("%d",&N);
		int max=0;
		for(int i=0;i<N;i++){
			scanf("%d",&num[i]);
			sign[num[i]]=1;
			if(num[i]>max)
				max=num[i];
		}
		int ret[1000],a=0;
		for(int i=1;i<=max;i++){
			if(sign[i]==1)
				ret[a++]=i;
		}
		int cnt=0,r;
		for(int i=0;i<a;i++){
			for(int j=i+1;j<a;j++){
				r=GCD(ret[i],ret[j]);
				if(r==1)
					cnt++;
			}
		}
		printf("case #%d:\n",k);
		printf("%d\n",cnt);
	}
	
	return 0;
}