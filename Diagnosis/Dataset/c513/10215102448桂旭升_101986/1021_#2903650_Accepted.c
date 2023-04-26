#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[26] = {'\0'};
char m[2500] = {'\0'};
typedef struct {
	char n[25];
} SCORE;

int fun(char c){
	int i = 0;
	for(i = 0; i < 26; i++){
		if(c == s[i])break;
	}
	return i;
}

int cmp(const void *a, const void *b){
    int i = 0, flag = 0; char ca, cb; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    while(pa -> n[i] != '\0' && (pb -> n)[i] != '\0'){
    	ca = pa -> n[i]; cb = pb -> n[i];
		if(pa -> n[i] >= 'a')ca = pa -> n[i] - 32;
		if(pb -> n[i] >= 'a')cb = pb -> n[i] - 32;
		if(cb == ca){i++;continue;}
		else{flag = 1;break;
		}
	}//printf("%c %c\n", ca, cb);
	if(flag == 1)return fun(ca) - fun(cb);
	
	else return pb->n[i]=='\0'?1:-1;
}

SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j = 0, k = 0;//printf("%d\n", n);
	long long temp;
    for(i = 0; i < n; i++){
        for(; j < strlen(m); j++){
        	if(m[j] == ' '){
        		a[i].n[k] = '\0';j++;break;
			}
			a[i].n[k] = m[j]; k++;
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
	while(1){
		if(scanf("%s", &s) == EOF)break;
		gets(m);gets(m);
		while(i < strlen(m)){
			if(m[i] == ' ')num++;i++;
		}
		A = Input(num+1);
		qsort(A, num+1, sizeof(SCORE), cmp);
		for(j = 0; j < num+1; j++){
			printf("%s", A[j].n);
			if(j != num)printf(" ");
			else printf("\n");
		}
		num = 0; i = 0;
	} 
}