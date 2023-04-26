#include <stdio.h>
#include <math.h>
int main(){
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		int x,y,diff=0,a[20],b[20],j=0,k=0;
		scanf("%d %d",&x,&y);
		if (x*y==0){
			x=x+y;
			if(x%2==0) diff=diff-1;
			while(x){
				diff++;
				x=x/2;
			}
			printf("%d\n",diff);
			continue;
		}
		while (x){
			a[j++]=x%2;
			x/=2;
		}
		while (y){
			b[k++]=y%2;
			y/=2;
		}
		int min;
		if(j<k) min=j;
		else min=k;
		diff=diff+abs(j-k);
		for (int m=0;m<min;m++){
			if (a[m]!=b[m]) diff++;
		}
		printf("%d\n",diff);
	}
	return 0;
}