#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	char d[50];
	char t[50];
	int si;
	char m[505];
}p;
int cmpname(const void* x,const void* y){
	return strcmp((*(p*) x).m,(*(p*) y).m)>0 ? 1:-1;
}
int cmpsize(const void* x,const void* y){
	if((*(p*)x).si!=(*(p*)y).si) return (*(p*)x).si>(*(p*)y).si;
	else return strcmp((*(p*) x).m,(*(p*) y).m)>0 ? 1:-1;
}
int cmptime(const void* x,const void* y){
	if(strcmp((*(p*) x).d,(*(p*) y).d)!=0) return strcmp((*(p*) x).d,(*(p*) y).d);
	else if(strcmp((*(p*) x).t,(*(p*) y).t)!=0) return strcmp((*(p*) x).t,(*(p*) y).t);
	else return strcmp((*(p*) x).m,(*(p*) y).m)>0 ? 1:-1;
}
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		p a[105];
		int i;
		for(i=0;i<n;i++){
			scanf("%s%s%d%s",a[i].d,a[i].t,&a[i].si,a[i].m);
		}
		char tt[50],t[50];
		scanf("%s%s",t,tt);
		//printf("%c\n",tt[1]);
		if(tt[1]=='N'){
			//printf("name");
			qsort((void *)a,n,sizeof(a[0]),cmpname);
		}
		else if(tt[1]=='S'){
			qsort((void *)a,n,sizeof(a[0]),cmpsize);
		}
		else{
			qsort((void *)a,n,sizeof(a[0]),cmptime);
		}
		for(i=0;i<n;i++){
			printf("%s %s %16d %s\n",a[i].d,a[i].t,a[i].si,a[i].m);
		}
		printf("\n");
	}
}