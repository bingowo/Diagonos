#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* p1,const void* p2){
	char* a = (char*)p1;
	char* b = (char*)p2;
	return strcmp(a,b); 
}
int main()
{
	int N;
	scanf("%d",&N);
	char data[100][200];
	for(int i=0;i<N;i++){
		scanf("%s",data[i]);
		if(data[i][4]=='s'){
			i--,N--;
		}
	}
	qsort(data,N,sizeof(data[0]),cmp);
	for(int i=0;i<N;i++){
		printf("%s\n",data[i]);
	}
	return 0;
 } 