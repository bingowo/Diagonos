#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
long long x, y;
typedef struct 
{
    long long a;
    long long b;
    long long q;
}LIST;
int cmp(const void *a, const void *b){
    LIST *pa = (LIST*)a, *pb = (LIST*)b;
    if(pa -> q != pb -> q)return pa -> q > pb -> q ? 1:-1;
    else if(pa -> a != pb -> a)return pa -> a > pb -> a ? 1 : -1;
    else return pa -> b > pb -> b ? 1 : -1;
}
long long uabs(long long a, long long b){
    return a > b? a-b : b-a;
}
long long max(long long a, long long b){
    return a > b ? a : b;
}
LIST* Input(int n)
{
    LIST *a = (LIST*)malloc(sizeof(LIST)*n);
    int i, j = 0, k = 0;
    for(i = 0; i < n; i++){
        scanf("%lld%lld", &a[i].a, &a[i].b);
        a[i].q = max(uabs(x, a[i].a), uabs(y, a[i].b));
    }
    return a; 
}
/*
long long min(long long a, long long b){
    return a < b ? a : b;;
}*/
int main(){
	int i, j, t, flag;
    LIST* A = NULL;
    scanf("%lld%lld", &x, &y);
    scanf("%d", &t);
    A = Input(t);
    qsort(A, t, sizeof(LIST), cmp);
    printf("%lld\n%lld %lld", A[0].q, A[0].a, A[0].b);
    free(A);
    system("pause");
	return 0;
}