#include<stdio.h>
#include<stdlib.h> 

int cmpA(const void *pa,const void *pb){
	int a = *(int *)pa;
	int b = *(int *)pb;
	return a - b;

} 
int cmpD(const void *pa,const void *pb){
	int a = *(int *)pa;
	int b = *(int *)pb;
	return b - a;
}



int main(){
	char way;
	int input[101],res[101];
	int num = 0,rnum = 1;
	scanf("%c",&way);
	do{
		scanf("%d",&input[num]);
		num ++;
	}
	while(getchar() != '\n');

	
	if (way == 'A') qsort(input,num,sizeof(int),cmpA);
	else qsort(input,num,sizeof(int),cmpD);  //排序 
	res[0]=input[0];
	for(int i = 1;i < num;i++){  //去重 
		if(input[i]!=input[i-1]){
			res[rnum] = input[i];
			rnum++;
		}
	}
    
	
	for(int i = 0;i < rnum;i++){
		printf("%d%c",res[i],(i == rnum -1? '\n':' '));
	}
	return 0;
}