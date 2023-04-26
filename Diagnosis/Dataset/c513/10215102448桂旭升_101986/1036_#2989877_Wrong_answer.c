#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
typedef struct{
    long long x;
    long long y;
    long long man;
}MAN;

int power(long long a){
    long long wide = 1, n = 0;
    while(wide < a){
        wide*=2; n++;
    }
    return n;
}

int cmp(const void *a, const void *b){
    int i = 0, flag = 0; char ca, cb; MAN *pa = (MAN *)a, *pb = (MAN *)b;//printf("%c %c\n", ca, cb);
	if(pa -> man != pb -> man)return pa -> man > pb -> man ? -1 : 1;
	else if(pa -> x != pb -> x)return pa -> x > pb -> x ? 1 : -1;
	else return pa -> y > pb -> y ? 1 : -1;
}

MAN* Input(int n)
{
    MAN *a = (MAN*)malloc(sizeof(MAN)*n);
    int i, j = 0, k = 0;//printf("%d\n", n);
	long long temp;
    for(i = 0; i < n; i++){
    	scanf("%lld%lld", &a[i].x, &a[i].y);
        a[i].man = (long long)(fabs(a[i].x) + fabs(a[i].y));
	}
    return a; 
}

int main(){
    MAN* A = NULL;
	int i, n, ans = 0, temp;
	scanf("%d", &n);
	A = Input(n);
    qsort(A, n, sizeof(MAN), cmp);
    printf("%lld\n", (long long)(fabs(A[0].x - A[1].x) + fabs(A[0].y - A[1].y)));
    for(i = 0; i < n-1; i++){
        temp = (long long)(fabs(A[i].x - A[i+1].x) + fabs(A[i].y - A[i+1].y));
        if(temp % 2 == 0)break;
        ans += power(temp);
    }
    printf("%d", ans);
    system("pause");
	return 0;
} 