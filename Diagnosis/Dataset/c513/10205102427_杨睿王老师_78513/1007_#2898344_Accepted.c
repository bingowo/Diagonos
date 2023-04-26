//1007
#include <stdio.h>
#include <math.h>
int main(){
	int i,T;
	scanf("%d",&T);
	char ch=getchar();
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		int n,l=0,j,max=0;
		scanf("%d",&n);
		int b[33];
		for(j=0;j<33;j++){
			b[j]=0;
		}
		while(n>0){
			b[l]=n%2;
			n/=2;
			l++;
		}
		int cnt=1;
		for(j=0;j<l-1;j++){
			//printf("%d",b[j]);
			if(b[j]!=b[j+1]){
				cnt++;
			}
			else{
				if(cnt>max){
					max=cnt;
				}
				cnt=1;
			}
		}
		if(cnt>max){
			max=cnt;
		}
		printf("%d\n",max);
	}
}