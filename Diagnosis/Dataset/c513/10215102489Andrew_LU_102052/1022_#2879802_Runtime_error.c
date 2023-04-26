#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char n1[1005];
	char n2[1005];	
}p;
int cmp1(const void* a, const void* b){
	if(strcmp((*(p*)a).n2,(*(p*)b).n2)!=0) return strcmp((*(p*)a).n2,(*(p*)b).n2);
	else return strcmp((*(p*)b).n1,(*(p*)a).n1);
}
int main(){
	int i,n,j;
	p a[500];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char t[100005];
		scanf("%s",t);
		int f=0;
		int l1=0,l2=0;
		for(j=0;j<strlen(t);j++){
			if(t[j]=='@') f=1;
			else if(f==0) a[i].n1[l1++]=t[j];
			else a[i].n2[l2++]=t[j];
		}
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	for(i=0;i<n;i++){
		printf("%s@%s\n",a[i].n1,a[i].n2);
	}
}