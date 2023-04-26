#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include<ctype.h>
int d;
typedef struct 
{
    double a;
    double b;
}LIST;
int cmp(const void *a, const void *b){
    LIST *pa = (LIST*)a, *pb = (LIST*)b;
    return (pa -> a / pa -> b) < (pb -> a / pb -> b) ? 1 : -1;
}
LIST* Input(int n)
{
    LIST *a = (LIST*)malloc(sizeof(LIST)*n);
    int i, j = 0, k = 0;
    double temp;
    for(i = 0; i < n; i++){
        scanf("%lf%lf", &temp, &a[i].b);
        a[i].a = d - temp;
    }
    return a; 
}
int main(){
	int i, j, t, n, flag;
    scanf("%d", &d);
    scanf("%d", &n);
    LIST* A = NULL; 
    A = Input(n);
    qsort(A, n, sizeof(LIST), cmp);
    printf("%.6f", d/(A[0].a/A[0].b));
    free(A);
    system("pause");
	return 0;
}