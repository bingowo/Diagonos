#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp (const void *a, const void *b);

int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	int positive[100000];
	int negative[100000];
	int i, x;
	int ppl = 0;
	int npl = 0;
	for (i = 0; i < n; i++){
		scanf("%d",&x);
		if (x < 0){
			negative[npl] = -x;
			npl ++;
		}else{
			positive[ppl] = x;
			ppl ++;
		}
	}
	int lengthOfPos = ppl + 1;
	int lengthOfNeg = npl + 1;
	qsort(positive,ppl,sizeof(int),cmp);
	qsort(negative,npl,sizeof(int),cmp);
	int answer = 0;
	int j;
	for(j = 0; j < lengthOfPos - 1; j = j + 2 ){
		answer = positive[j] - positive[j+1] + answer;
	}
	for(j = 0; j < lengthOfNeg - 1; j = j + 2 ){
		answer = negative[j] - negative[j+1] + answer;
	}
	if (lengthOfPos % 2 == 1){
		answer = answer + positive[lengthOfPos-1] + negative[lengthOfNeg-1];
	}
	printf("%d",answer);
	return 0;
}

int cmp (const void *a, const void *b){
	return (*(int *)b) - *((int *)a);	
}


