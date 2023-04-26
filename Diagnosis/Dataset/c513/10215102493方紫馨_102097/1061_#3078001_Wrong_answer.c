#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
	char s[10001];
	long long n;
};

int cmp(const void* p1,const void* p2){
	struct data* a = (struct data*)p1;
	struct data* b = (struct data*)p2;
	if(a->n!=b->n)
		return a->n-b->n;
	return strcmp(a->s,b->s);
}

int main()
{
	int T;
	scanf("%d",&T);
	struct data p[10000];
	for(int k=0;k<T;k++){
		int alph[128]={0},d=1,N;
		memset(alph,-1,128*4);
		scanf("%s",p[k].s);
		for(int i=0;i<strlen(p[k].s);i++){
			if(alph[p[k].s[i]]==-1){
				alph[p[k].s[i]]=d;
				if(d==1)
					d=0;
				else if(d==0)
					d=2;
				else
					d++;
			}
		}
		if(d<2)
			d=2;
		p[k].n=0;
		for(int i=0;i<strlen(p[k].s);i++){
			p[k].n = p[k].n*d+alph[p[k].s[i]];
		}
	}
	qsort(p,T,sizeof(p[0]),cmp);
	for(int i=0;i<T;i++){
		printf("%s\n",p[i].s);
	}
	
	return 0;
}