#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 1000
struct data{
	int a;
	int t;
};
int cmp(const void *a, const void *b){
	struct data a1,a2;
	a1=*(struct data*)a; a2=*(struct data*)b;
	if(a1.t-a2.t) return a2.t-a1.t;
	else return a1.a-a2.a;
}
int main(){
	struct data *c;int i=0;
	c=(data*)malloc(sizeof(data)*MAX);
	while(scanf("%d",&c[i].a)!=EOF) i++; 
	int s=i; i--;
	while(i>=0){
		int d=c[i].a;
		c[i].t=0;
		while(d){
			c[i].t++;
			d/=10;
		}
		i--;
	}
	qsort(c,s,sizeof(c[0]),cmp);
	for(i=0;i<s;i++) printf("%d ",c[i].a);
	return 0;
}