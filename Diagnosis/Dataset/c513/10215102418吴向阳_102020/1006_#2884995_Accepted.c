#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	int a[128];
	char b[20];
	a['-']=-1,a['0']=0,a['1']=1;
	for (int i=0;i<T;i++){
		scanf("%s",b);
		char *p=b;
		int sum=0;
		while(*p){
			sum=sum*3+a[*p++];
		}
		printf("case #%d:\n%d\n",i,sum);
	}
	return 0;
} 