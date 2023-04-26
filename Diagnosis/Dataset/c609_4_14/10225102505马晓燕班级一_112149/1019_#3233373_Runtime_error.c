#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;int bits;
}INT;
int get_bit(int x)
{
	int bit=0;
	if(x < 0)
		x = -x;
	while(x){
		bit++;
		x/=10;
	}
	return bit;
}

int cmp(const void* a,const void* b )
{
	INT* m = (INT *)a , *n = (INT *)b;
	if(m->bits == n->bits)
		return m->num > n->num;
	else
		return n->bits - m->bits;
}
int main()
{
	INT a[100005];
	int m=0;
	while(scanf("%d",&(a[m].num)) != EOF){
		a[m].bits = get_bit(a[m].num);
		m++;
	}
	qsort(a,m,sizeof(INT),cmp);
	
	for(int i=0;i<m;i++){
		printf("%d%c",a[i].num, i == m? '\n' : ' ');
	}
	return 0;
}