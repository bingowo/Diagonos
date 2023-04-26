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
	int input[1001],res[101];
	int num = 0,rnum = 0;
	scanf("%c",&way);
	while(scanf("%d",&input[num ++] != EOF));
	if (way == 'A') qsort(input,num+1,sizeof(int),cmpA);
	else qsort(input,num+1,sizeof(int),cmpD);
	for(int i = 0;i < num;i++){  //去重 
		if(input[i]!=input[i+1]){
			res[rnum++] = input[i];
		}
	}
	
	for(int i = 0;i < rnum;i++){
		printf("%d%c",res[i],(i == rnum-1 ? '/n':' '));
	}
	return 0;
}