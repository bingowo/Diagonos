#include<stdio.h>
#include<stdlib.h>

typedef struct{
	long long num;
	int onenum;
}NUM;

int cmp(const void*p1,const void*p2);

int main(void)
{
	int T;
	scanf("%d",&T);
	
	for(int i = 0; i < T; i++){
		int N;
		scanf("%d",&N);
		
		NUM data[N];
		unsigned long long temp = 0;
		for(int v = 0; v < N; v++){
			scanf("%lld",&data[v].num);
			temp = (unsigned long long)data[v].num;
			data[v].onenum = 0;
			while(temp != 0){
				if(temp % 2) data[v].onenum++;
				temp >>= 1;
			}
		}

		qsort(data,N,sizeof(NUM),cmp);
		
		printf("case #%d:\n",i);
		printf("%lld",data[0].num);
		for(int v = 1; v < N; v++) 
			printf(" %lld",data[v].num);
		putchar('\n');
    }
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	NUM a = *(NUM*)p1;
	NUM b = *(NUM*)p2;
	if(a.onenum != b.onenum) return b.onenum - a.onenum;
	else return a.num > b.num?1:a.num < b.num?-1:0;
}