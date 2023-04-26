#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct{
	int arr[100];
}data;
int cmp(const void *a,const void *b){
	data da=*((data*)a),db=*((data*)b);
	int index=0;
	while(da.arr[index]!=-1&&db.arr[index]!=-1){
		if(da.arr[index]>db.arr[index]){
			return -1;
		}
		else if(da.arr[index]<db.arr[index]){
			return 1;
		}
		else{
			index++;
		}
	}
	if(da.arr[index]==-1){
		return 1;
	}
	else{
		return -1;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=0;cas<T;cas++){
		int n;
		scanf("%d",&n);
		data darr[1000];
		for(int i=0;i<n;i++){
			for(int j=0;j<100;j++){
				scanf("%d",&darr[i].arr[j]);
				if(darr[i].arr[j]==-1){
					break;
				}
			}
		}
		qsort(darr,n,sizeof(int)*100,cmp);
		for(int i=0;i<n;i++){
			for(int j=0;j<100;j++){
				if(darr[i].arr[j]==-1){
					printf("\n");
					break;
				}
				else{
					printf("%d ",darr[i].arr[j]);
				}
			}
		}
	}
	return 0;
}