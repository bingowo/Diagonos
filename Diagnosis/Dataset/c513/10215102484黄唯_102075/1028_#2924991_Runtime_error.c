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


int myremove(int input[],int res[]){
	int n = sizeof(input) / sizeof(input[0]);
	
	int rn = 0;
	int flag = 0;  //元素重复标志 
	for(int i = 0;i < n;i++){
		for(int j = 0;j < rn ;j++){
			if(res[j] == input[i]) flag = 1;
		} 
		if(flag == 0){
			res[rn++] = input[i];
		}
		
		}
		
	
	res[rn] ='\0';
	
}



int main(){
	char way;
	int input[1001],res[101];
	int num = 0,rnum = 0;
	scanf("%c",&way);
	while(scanf("%d",&input[num ++] != EOF));
	if (way == 'A') qsort(input,num+1,sizeof(int),cmpA);
	else qsort(input,num+1,sizeof(int),cmpD);
	myremove(input,res);
	rnum = sizeof(res) / sizeof(int);
	for(int i = 0;i < rnum;i++){
		printf("%d%c",res[i],(i == rnum-1 ? '/n':' '));
	}
	return 0;
}