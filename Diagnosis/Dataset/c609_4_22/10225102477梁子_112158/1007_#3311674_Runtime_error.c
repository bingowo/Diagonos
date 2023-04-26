#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
	long long int a;
	int number;
};
int cmp(const void*a,const void*b){
	struct data d1,d2;
	d1=*((struct data*)a);
	d2=*((struct data*)b);
	if(d2.number!=d1.number)
	return d2.number-d1.number;
	else{
		if(d1.a>d2.a)return 1;
		else return -1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	int i=0;
	for(;i<T;i++){
	 printf("case #%d:",i);
	 struct data p[10000];
     int n;
	 scanf("%d",&n);
	 int j=0;
	 for(;j<n;j++);
	 {
	 	scanf("%lld",p[j].a);
	 	int d=1;
	 	p[j].number=0;
	 	int k=0;
	 	for(;k<64;k++){
	 		if(p[j].a&d)p[j].number++;
	 		d=d<<1;
		 }
		}
	  int l=0;
	  qsort(p,n,sizeof(p[0]),cmp);
	  for(;l<n-1;l++){
	  	printf("%lld",p[l].a);
	  	printf("\n");
	  }	
    }
    return 0;
 } 