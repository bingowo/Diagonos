#include<stdio.h>
#include<string.h>
int main(){
	int chance;
	scanf("%d",&chance);
	int i,j,key=1;
	for(i=0;i<chance;i++){
		int a[9],key1=0; //key用来判断是否有输出
		printf("case #%d:\n",i); 
		for(j=0;j<9;j++){
			scanf("%d",&a[j]);
			if(key1&&j!=0&&a[j]&&a[j]>0) printf("+");
			if(j!=8&&a[j]&&a[j]!=1&&a[j]!=-1&&j!=7) {printf("%dx^%d",a[j],8-j);key1=1;} 
			if(j!=8&&a[j]==1&&j!=7) {printf("x^%d",8-j);key1=1;}
			if(j!=8&&a[j]==-1&&j!=7) {printf("-x^%d",8-j);key1=1;} 
			if(j==7&&a[j]==1) {printf("x");key1=1;} 
			if(j==7&&a[j]==-1) {printf("-x");key1=1;} 
			if(j==7&&a[j]!=-1&&a[j]&&a[j]!=1) {printf("%dx",a[j]);key1=1;}
		}
		if(a[8]) printf("%d",a[8]); 
		for(j=0;j<9;j++){
			if(a[j]!=0){
				key=0;
				break;
			}
		}
		if(key==1){
			printf("0");
		}
		printf("\n");
	}
}