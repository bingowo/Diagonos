#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	int*c=(int *)a;
	int*d=(int *)b;
	if(*c==*d) return 0;
	else return *c>*d?1:-1;
}
int main(){
	int A,B;
	int a[1000],b[1000],c[1000]={0},d[1000]={0};
	scanf("%d\n",&A);
	for(int v=0;v<A;v++) scanf("%d ",&a[v]);
	scanf("%d\n",&B);
	for(int v=0;v<B;v++) scanf("%d ",&b[v]);
	//c存A中有的数 
	int r=0;
	for(int i=0;i<A;i++) {
		for(int j=0;j<B;j++){
			if(a[i]==b[j]) {c[r++]=a[i];b[j]=-1;break;}
			else continue;
		}
	}
	//d存b有a无的数 
	int z=0;
	for(int v=0;v<B;v++){
		if(b[v]!=-1) d[z++]=b[v];
	}
	qsort(d,z,sizeof(int),cmp);
	for(int g=0;g<r;g++) printf("%d ",c[g]);
	for(int g=0;g<z;g++) printf("%d ",d[g]);
	return 0;
}