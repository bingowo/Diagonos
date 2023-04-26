//1008
#include <stdio.h>
#include <math.h>

int main(){
	int i,T;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int n[50],m[50];
		int j,q=0,w=0;
		for(j=0;j<50;j++){
			n[j]=0;
			m[j]=0;
		}
		int max;
		if(a>b) max=a;
		else max=b;
		while(max>0){
			n[q]=a%2;
			a/=2;
			q++;
			m[w]=b%2;
			b/=2;
			w++;
			max/=2;
		}
		int cnt=0;
		for(j=0;j<50;j++){
			if(n[j]!=m[j]) cnt++;
		}
		printf("%d\n",cnt);
	}
}