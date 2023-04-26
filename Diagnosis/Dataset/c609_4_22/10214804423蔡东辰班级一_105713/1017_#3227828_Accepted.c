#include <stdio.h>
#include <stdlib.h>
static int cmp(const void* a, const void *b);
int main(){
	char mode, temp;
	int t, cnt = 0;//t用来存输出时的上一个值
	scanf("%c", &mode);
	int array[100];
	for(cnt; cnt<100; cnt++){
		scanf("%d", &array[cnt]);
		if((temp = getchar()) == '\n'){
			cnt++;
			break;
		}
	}
	qsort(array, cnt, sizeof(int), cmp);
	if(mode=='A'){
		t = array[0];
		int judge = (cnt==1)?printf("%d", array[0]):printf("%d ", array[0]);
		for(int i = 0; i < cnt; i++){
			if(array[i] != t && i<cnt-1){
				printf("%d ", array[i]);
				t = array[i];
			}
			else if(array[i] != t && i==cnt-1){
				printf("%d", array[i]);
			}
		}
	}
	else{
		t = array[cnt-1];
		int judge = (cnt==1)?printf("%d", array[cnt-1]):printf("%d ", array[cnt-1]);
		for(int i = cnt-1; i > -1; i--){
			if(array[i] != t && i > 0){
				printf("%d ", array[i]);
				t = array[i];
			}
			else if(array[i] != t && i==0){
				printf("%d", array[i]);
			}
		}
	}
	return 0;
}
static int cmp(const void*a, const void* b){
	return *((int*)a)-*((int*)b);
}