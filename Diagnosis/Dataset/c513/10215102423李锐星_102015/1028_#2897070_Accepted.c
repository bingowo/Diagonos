#include <stdio.h>
#include <stdlib.h> 

int cmp1(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}

int cmp2(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}
int main()
{
	int list[101];
	int i=0;
	char c;
	scanf("%c",&c);
	while(scanf("%d",&list[i])!=EOF){
		i++;
	}
	if (c=='A'){
		qsort(list,i,sizeof(int),cmp1);
	}
	else{
		qsort(list,i,sizeof(int),cmp2);
	}
	int j;
	for (j=0;j<i-1;j++){
		if (list[j]!=list[j+1]){
			printf("%d",list[j]);
			printf(" ");
		}
	}
	printf("%d\n",list[i-1]);
	return 0;
}