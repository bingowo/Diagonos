#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct {
	double l;
    double c;
} SCORE;
double d[2] = {0.0};
int cmp(const void *a, const void *b){
    int t; SCORE *pa = (SCORE *)a, *pb = (SCORE *)b;
    if((pa -> c) != (pb -> c)) return (pa -> c) > (pb -> c) ? 1 : -1;
    if((pa -> l) != (pb -> l)) return (pb -> l) > (pa -> l) ? 1 : -1;
}
SCORE* Input(int n)
{
    SCORE *a = (SCORE*)malloc(sizeof(SCORE)*n);
    int i;
    for(i = 0; i < n; i++){
        scanf("%lf", &d[0]);scanf("%lf", &d[1]);  a[i].l = sqrt(d[0]*d[0] + d[1]*d[1]);
		if(d[0] > 0 && d[1] > 0)a[i].c = fabs(atan(d[1]/d[0]));
		if(d[0] < 0 && d[1] > 0)a[i].c = 1.5708 + fabs(atan(d[1]/d[0]));
		if(d[0] < 0 && d[1] < 0)a[i].c = 2*1.5708 + fabs(atan(d[1]/d[0]));
		if(d[0] > 0 && d[1] < 0)a[i].c = 3*1.5708 + fabs(atan(d[1]/d[0]));
		if(d[0] == 0 && d[1] == 0)a[i].c = 0;
		if(d[0] == 0 && d[1] > 0)a[i].c = fabs(atan(d[1]/d[0]));
		if(d[0] == 0 && d[1] < 0)a[i].c = 3*1.5708;
		if(d[0] < 0 && d[1] == 0)a[i].c = 2*1.5708;
		if(d[0] > 0 && d[1] == 0)a[i].c = 0;//printf("a = %llf %llf\n", a[i].l, a[i].c);
    }
    return a; 
}
int main(){
	SCORE *A = NULL;
	int t, i, j, n;//printf("%.4lf\n", sqrt(0.01));
	scanf("%d", &t);
	scanf("%d", &n);
	scanf("%lf", &d[0]);
	printf("%lf", d[0]);
	free(A);
	return 0;
} 