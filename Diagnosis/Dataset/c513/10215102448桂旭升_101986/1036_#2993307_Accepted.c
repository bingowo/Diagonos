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
    unsigned long long ans;
    if(a>=0&&b<=0)ans = a - b;
    else if(a <= 0 && b >= 0)ans = b - a;
    else if(a < b && a > 0)ans = b - a;
    else{
        long long t = a - b;
        if (t > 0)ans = t;
        else ans = -t;
    }//printf("%llu\n", ans);
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
	int i = 0, n, ans = 0;
    unsigned long long temp;
    int a[25] = {0};
	scanf("%d", &n);
	A = Input(n);
    qsort(A, n, sizeof(MAN), cmp);
    unsigned long long a1 = uabs(A[0].x, A[1].x);
    unsigned long long a2 = uabs(A[0].y, A[1].y);
    if(a1 == a2 && a1 == (unsigned long long)9223372036854775808)printf("18446744073709551616\n");
    else{
        printf("%llu\n", a1 + a2);
    }
    
    while(A[i].x == A[i+1].x && A[i].y == A[i+1].y)i++;
    for(; i < n-1; i++){
        unsigned long long a1 = uabs(A[i].x, A[i+1].x);
        unsigned long long a2 = uabs(A[i].y, A[i+1].y);//printf("a1 = %llu a2 = %llu\n", a1, a2);
        if(a1 == a2 && a1 == (unsigned long long)9223372036854775808){
            break;
        }
        else{
            temp = a1 + a2;
            if(temp % 2 == 0)break;
            ans += power(temp);
        }
        
    }
    printf("%d", ans);
    system("pause");
	return 0;
} 