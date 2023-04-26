#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	int na = *(int *)a;
	int nb = *(int *)b;
	return na > nb ? 1 : -1 ;
}

int main(){
    int a[1001] = {0};
    long long int b[500501] = {0};
    int cnt = 0;
    for(int j=1;j<=n;j++) {
        scanf("%d",a+j);
        a[j] += a[j-1];
    }
    for(int len=1;len<=n;len++)
    for(int i=1;i<=n-len+1;i++)
    b[++cnt]=a[i+len-1]-a[i-1];
    qsort(b, 500501, sizeof(b), cmp); 
    for(int i=1;i<=cnt;i++)
    b[i] += b[i-1];
    printf("case #%d:\n %d",b[j]-b[i-1]);