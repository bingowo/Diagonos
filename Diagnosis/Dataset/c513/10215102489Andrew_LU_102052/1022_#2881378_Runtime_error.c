#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char *n1;
	char *n2;	
}p;
int cmp1(const void* a, const void* b){
	if(strcmp((*(p*)a).n2,(*(p*)b).n2)!=0) return strcmp((*(p*)a).n2,(*(p*)b).n2);
	else return strcmp((*(p*)b).n1,(*(p*)a).n1);
}
int main(){
	int i,n,j;
	//char *p=(char *)malloc(sizeof(int)*1e6);
	scanf("%d",&n);
	p *a=(p*)malloc(sizeof(p)*n);
	for(i=0;i<n;i++){
		//printf("%d %d\n",i,n);
		char *t=(char *)malloc(sizeof(char)*1e6/n+50);
		scanf("%s",t);//printf("%d\n",strlen(t));
		char *t1,*t2;
		//t1=(char *)malloc(sizeof(char)*strlen(t));
		//t2=(char *)malloc(sizeof(char)*strlen(t));
		a[i].n1=(char *)malloc(sizeof(char)*strlen(t));
		a[i].n2=(char *)malloc(sizeof(char)*strlen(t));
		int f=0;
		int l1=0,l2=0;
		//printf("st=%d",strlen(t));
		/*for(j=0;j<strlen(t);j++){
			if(t[j]=='@') f=1;
			else if(f==0) t1[l1++]=t[j];
			else t2[l2++]=t[j];
			//printf(".");
		}*/ 
		a[i].n1 = strtok(t,"@");
        a[i].n2 = strtok(NULL,"@");
		//printf("%s\n%s\n",a[i].n1,a[i].n2);
		//strcpy(a[i].n1,t1);
		//strcpy(a[i].n2,t2);
		//printf("sdfsd");
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	for(i=0;i<n;i++){
		printf("%s@%s\n",a[i].n1,a[i].n2);
	}
}