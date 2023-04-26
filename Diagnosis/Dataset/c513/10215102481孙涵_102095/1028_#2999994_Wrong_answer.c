#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cmpA(const void* a, const void* b);
int cmpD(const void* a, const void* b);

int main(int argc, char *argv[]) {
	char AD;
	scanf("%c",&AD);
	int n[100];
	int *p = n;
	int lengthOfN = 0;
	while (scanf("%d",p++) != EOF){
		lengthOfN++;
	}
	if (AD == 'A'){  //升序 
		qsort(n,lengthOfN,sizeof(int),cmpA); 
	}else if (AD == 'D'){ //降序 
		qsort(n,lengthOfN,sizeof(int),cmpD);
	}
	int i,j;
	for ( i = 0; i < lengthOfN - 2; i++){
		if (n[i] == n[i + 1]){
			for (j = i+1; j < lengthOfN - 1; j++){
				n[j] = n[j+1];
			}
			n[lengthOfN-1] = 0;
			lengthOfN --;
		}
	}
	for (i = 0; i < lengthOfN-1; i++){
		printf("%d ",n[i]);
	}
	return 0;
}

int cmpA(const void* a, const void* b){
	return *((int *)a) - *((int *)b);
}

int cmpD(const void* a, const void* b){
	return *((int *)b) - *((int *)a);
}