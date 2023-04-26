#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

typedef struct Alpha{
	double f;
	char alpha;
	int number;
}A;
int cmp(const void* x, const void * y){
	A xx = *(A*)x;
	A yy = *(A*)y;
	xx.f*=100;
	yy.f*=100;
	if(xx.f==yy.f){
		char a=tolower(yy.alpha);
		char b=tolower(xx.alpha);
		if(a==b){
			return yy.alpha-xx.alpha;
		}
		else{
			return a-b;
		}
	}
	return yy.f-xx.f;
}
int main(){
	int i,T;
	scanf("%d",&T);	
	for(i=0;i<T;i++){
		printf("case #%d:\n",i);
		double table[27];
		for(int y=0;y<27;y++){
			scanf("%lf",&table[y]);
		}
		A a[110];
		for(int r=0;r<110;r++){
			a[r].alpha='\0';
			a[r].f=0;
		}
		char ch;
		int l=0;
		while((ch=getchar())!='\n'){
			a[l].alpha=ch;
			if(ch>='a'&&ch<='z'){
				a[l].f=table[a[l].alpha-97];
			}
			else{
				a[l].f=table[a[l].alpha-65];
			}
			a[l].number=a[l].alpha-97;
			l++;
		}
		qsort(a,l,sizeof(A),cmp);
		for(int y=0;y<l;y++){
			printf("%c",a[y].alpha);
		}
		printf("\n");
	}
}