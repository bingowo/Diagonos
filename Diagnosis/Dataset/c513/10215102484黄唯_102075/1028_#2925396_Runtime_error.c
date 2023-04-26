#include<stdio.h>

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
	int num = 0,rnum = 0;
	scanf("%c",&way);
	while(scanf("%d",&input[num ++] != EOF));
	if (way == 'A') qsort(input,num-1,sizeof(int),cmpA);
	else qsort(input,num-1,sizeof(int),cmpD);
	res[0]=input[0];
	for(int i = 1;i < num+1;i++){  //去重 
		if(input[i]!=input[i-1]){
			res[rnum++] = input[i];
		}
	}
	
	for(int i = 0;i < rnum+1;i++){
		printf("%d%c",res[i],(i == rnum ? '/n':' '));
	}
	return 0;
}