#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int trans(char* m)
{  
   static char* month[]   =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};   
 
    for (int i=0;; i++)     
          if (!strcmp(m,month[i])) return i;  
}


typedef struct{
	int r;
	char y[10];
	int n;
	int val;
}cal;

int cmp(const void *a,const void *b){
	cal *A=(cal *)a;
	cal *B=(cal *)b;
	if(A->val>B->val)
	return 1;
	return -1;
}

int main(){
	int T;
	int k=0;
	scanf("%d",&T);
	while(T--){
	int s;
	scanf("%d",&s);	
	cal a[s];
	for(int i=0;i<s;i++){
		scanf("%d. %s %d",&a[i].r,&a[i].y,&a[i].n);
		int yy=trans(a->y)+1;
		a[i].val=yy*100+a[i].n*1000+a[i].r;
	}

	qsort(a,s,sizeof(a[0]),cmp);
	printf("case #%d:\n",k);
	for(int i=0;i<s;i++)
	printf("%d. %s %d\n",a[i].r,a[i].y,a[i].n);
	k++;
	
	}
	return 0;
}