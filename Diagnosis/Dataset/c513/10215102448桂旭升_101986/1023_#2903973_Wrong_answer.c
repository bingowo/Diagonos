#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char m[3500] = {'\0'};
typedef struct {
	char n[35];
	int real;
	int t;
} SCORE;

int cmp(const void *a, const void *b){
    int i = 0, flag = 0; char ca, cb; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;//printf("%c %c\n", ca, cb);
	if(pa -> t != pb -> t)return pa -> t - pb -> t;
	else return strcmp(pa -> n, pb -> n);
}

SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j = 0, k = 0;//printf("%d\n", n);
	long long temp;
    for(i = 0; i < n; i++){
    	a[i].t = 1;a[i].real = 0;
        for(; j < strlen(m); j++){
        	if(m[j] == ' '){
        		a[i].n[k] = '\0';j++;break;
			}
			else if(isdigit(m[j])){
				a[i].t = a[i].t*10 + (m[j] - '0');
				a[i].real = a[i].real*10 + (m[j] - '0');
			}
			else {
				a[i].n[k] = m[j]; k++;
			}
			if(j == strlen(m) - 1){
        		a[i].n[k] = '\0';break;
			}
		}
		k = 0;
	}
    return a; 
}

int main(){
	int i = 0, num = 0, j;
	SCORE *A = NULL;
		gets(m);
		while(i < strlen(m)){
			if(m[i] == ' ')num++;i++;
		}
		A = Input(num+1);
		qsort(A, num+1, sizeof(SCORE), cmp);
		for(j = 0; j < num+1; j++){
			printf("%s", A[j].n);
			if(A[j].t != 1)printf("%d", A[j].real);
			if(j != num)printf(" ");
			else printf("\n");
		}
}