#include<stdio.h>
#include<stdlib.h>
int ucmp(const void*a, const void*b){
	return (*(int*)a-*(int*)b);//升序排序
}
int lcmp(const void*a, const void*b){
	return -(*(int*)a-*(int*)b);//降序排序
}
int main(){
	int inp[100]={0};
	char ge;
	ge = getchar();
	int num = 0;
	while(1){
		scanf("%d", &inp[num++]);
		if(getchar()=='\n')break;
	}
	
	if(ge=='A'){
		qsort(inp, num, sizeof(int), ucmp);
	}
	if(ge=='D'){
		qsort(inp, num, sizeof(int), lcmp);
	}
	int tep=inp[0];
	for(int i=0;i<num;i++){
		if(i==0){
			printf("%d ", tep);
			continue;
		}
		if(tep!=inp[i]){
		printf("%d ", tep);
		tep = inp[i];
		continue;
		}
	}
	return 0;
}