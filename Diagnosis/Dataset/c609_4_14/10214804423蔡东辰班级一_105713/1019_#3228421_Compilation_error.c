// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// typedef struct{
// 	int bits;
// 	char number[12];
// }NUM;
// static int cmp(const void*a, const void* b);
// int main(){
// 	int cnt = 0;
// 	char temp;
// 	NUM* array = (NUM*)malloc(sizeof(NUM)*1000000);
// 	for(cnt; cnt < 1000000; cnt++){
// 		NUM n;
// 		scanf("%s", n.number);
// 		n.bits = (n.number[0] == '-')? strlen(n.number)-1 : strlen(n.number);
// 		array[cnt] = n;
// 		if((temp = getchar()) == '\n'){
// 			cnt++;
// 			break;
// 		}	
// 	}
// 	qsort(array, cnt, sizeof(NUM), cmp);
// 	for(int i = 0; i<cnt; i++){
// 		printf("%s", array[i].number);
// 		if(i != cnt-1){
// 			printf(" ");
// 		}
// 	}
// 	free(array);
// 	return 0;
// }
// static int cmp(const void* a, const void* b){
// 	NUM x = *((NUM*)a);
// 	NUM y = *((NUM*)b);
// 	if(x.bits == y.bits){
// 		return atoi(x.number) - atoi(y.number);
// 	}
// 	return y.bits - x.bits;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char number[12];
}NUM;
static int cmp(const void*a, const void* b);
int main(){
	int cnt = 0;
	char temp;
	NUM* array = (NUM*)malloc(sizeof(NUM)*1000000);
	do{
		NUM n;
		scanf("%s", n.number);
		array[cnt++] = n;
	}while((temp = getchar()) != '\n');
	qsort(array, cnt, sizeof(NUM), cmp);
	for(int i = 0; i<cnt; i++){
		printf("%s", array[i].number);
		if(i != cnt-1){
			printf(" ");
		}
	}
	free(array);
	return 0;
}
static int cmp(const void* a, const void* b){
	NUM x = *((NUM*)a);
	NUM y = *((NUM*)b);
	int x_bits = (x.number[0] == '-')? strlen(n.number)-1 : strlen(n.number);
	int y_bits = (y.number[0] == '-')? strlen(n.number)-1 : strlen(n.number);
	if(x_bits == y_bits){
		return atoi(x.number) - atoi(y.number);
	}
	return y_bits - x_bits;
}