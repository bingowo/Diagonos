#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int n[100000] = {0};
int cmp(const void *a, const void *b){
    int i = 0, flag = 0; char ca, cb; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;//printf("%c %c\n", ca, cb);
	if(pa -> t != pb -> t)return pa -> t - pb -> t;
	else if(pa -> real != pb -> real)return pa -> real - pb -> real;
	else return strcmp(pa -> n, pb -> n);
}

int main(){
	int i = 0, num = 0, j;
	scanf("%d", &num);
	for(i = 0; i < num; i++){
		
	}
		while(i < strlen(m)){
			if(m[i] == ' ')num++;i++;
		}
		if(num+1 == 1) printf("%s", m);
		else{
			A = Input(num+1);
			qsort(A, num+1, sizeof(SCORE), cmp);
			for(j = 0; j < num+1; j++){
				printf("%s", A[j].n);
				//if(A[j].t != 1)printf("%d", A[j].real);
				if(j != num)printf(" ");
				else printf("\n");
			}
		}
}