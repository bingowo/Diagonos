#include<stdio.h>
int main(){
	int chance;
	scanf("%d",&chance);
	int i,j;
	for(i=0;i<chance;i++){
		int n;
		int key=1;
		int c[101][101]={{0,0}},a[101]={0},b[101]={0};
		int e,f;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d%d",&e,&f);
			if(c[e][f]==0){
				c[e][f]=1;
				a[e]++;
				b[f]++;
			}
		}
		for(j=0;j<101;j++){
			if(a[j]>1) key=0;
			else if(a[j]!=0&&b[j]!=0) key=0;
		}
		if(key!=0) printf("Lucky dxw!\n");
		else printf("Poor dxw!\n");
	}
}