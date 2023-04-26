#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
char y[1000000] = {'\0'};
typedef struct {
	char *num;
    char *s;
} SCORE;
int cmp(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    if(strcmp(pa -> s, pb -> s) != 0) return strcmp(pa -> s, pb -> s);
    else return (int)strcmp(pb -> num, pa -> num);
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i, j = 0, len, k = 0;
    char c;
    for(i = 0; i < n; i++){
        scanf("%s", &y); len = strlen(y);
		for(j = 0; j < len; j++){
			if(y[j] == '@')break;
			else a[i].num[j] = y[j];
		}
        a[i].num[j++] = '\0';
		for(; j < len; j++){
			a[i].s[k++] = y[j];
		}
		a[i].s[k++] = '\0';
		//printf("%d\n", strcmp("163.com", "163.com"));
		j = 0; k = 0;
    }
    return a; 
}
int main(){
	SCORE *A = NULL;
	int t, i, j;
	scanf("%d", &t);
	if(t == 1){
		scanf("%s", &y);printf("%s\n", y);
	}
	else{
		A = Input(t);
		//printf("A[0] %s %d %d\n", A[0].num, A[0].s, A[0].sum);
		qsort(A, t, sizeof(SCORE), cmp);
		for(i = 0; i < t; i++){
			printf("%s@%s\n", A[i].num, A[i].s);
		}
		free(A);
	}
	return 0;
}//printf("A[2] %d %d %d %d\n", A[2].num, A[2].score, A[2].win, A[2].lose);
		
	