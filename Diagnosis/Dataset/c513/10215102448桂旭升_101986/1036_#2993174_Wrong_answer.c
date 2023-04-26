#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
typedef struct{
    long long x;
    long long y;
    unsigned long long man;
}MAN;

unsigned long long uabs(long long a, long long b){
    unsigned long long ans = a - b;
    if(a < b)ans = b - a;
    return ans;
}

int power(unsigned long long a){
    unsigned long long wide = 1, n = 0;
    while(a != 0){
        a /= 2; n++;//printf("%d\n", n);
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
        a[i].man = uabs(a[i].x, 0) + uabs(a[i].y, 0);//printf("man = %llu\n", a[i].man);
	}
    return a; 
}

int main(){
    MAN* A = NULL;
	int i, n, ans = 0;
    unsigned long long temp;
    int a[25] = {0};
	scanf("%d", &n);
	A = Input(n);
    qsort(A, n, sizeof(MAN), cmp);
    temp = uabs(A[0].x, A[1].x) + uabs(A[0].y, A[1].y);
    printf("%llu\n", temp);
    for(i = 0; i < n-1; i++){
        temp = uabs(A[i].x, A[i+1].x) + uabs(A[i].y, A[i+1].y);
        if(temp % 2 == 0)break;
        ans += power(temp);
    }
    printf("%d", ans);
    system("pause");
	return 0;
} 