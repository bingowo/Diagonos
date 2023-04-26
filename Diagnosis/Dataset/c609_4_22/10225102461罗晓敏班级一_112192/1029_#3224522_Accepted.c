#include <stdio.h>
#include <stdlib.h>
typedef struct{                                   //value在a中下标subscript 
	int value;
	int subscript;
}sta;
int f1(int a[],int b,int t){                   //检查t是否在大小为b的a中出现过 
	int i;
	for(i=0;i<b;i++){
		if(t==a[i]){
			return i;
		}
	}
	return -1;
}
int cmp1(const void* a,const void* b){
	return ((sta*)a)->subscript-((sta*)b)->subscript;
}
int cmp2(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
int main(){
	int m,i;
	scanf("%d",&m);
	int a[m];
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	int n,j;
	scanf("%d",&n);
	sta *you=(sta*)malloc(n*sizeof(sta));int x=0; 
	int wu[n],y=0,temp,judge;
	for(j=0;j<n;j++){
		scanf("%d",&temp);
		judge=f1(a,m,temp);
		if(judge+1){
			you[x].value=temp;
			you[x].subscript=judge;
			x++;
		}else{
			wu[y]=temp;
			y++;
		}
	}
	qsort(you,x,sizeof(sta),cmp1);
	qsort(wu,y,sizeof(int),cmp2);
	for(i=0;i<x;i++){
		printf("%d ",you[i].value);
	}
	for(i=0;i<y;i++){
		printf("%d%c",wu[i],i==y-1?'\n':' ');
	}
	free(you);
}