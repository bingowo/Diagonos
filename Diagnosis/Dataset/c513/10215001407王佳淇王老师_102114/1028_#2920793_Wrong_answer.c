#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmpup(const void*a,const void*b){//升序排列 
	int *a1=(int *)a;
	int *b1=(int *)b;
	if(*a1!=*b1) return *a1-*b1;
    else return 0;
}
int cmpdown(const void*a,const void*b){//降序排列 
	int *a1=(int *)a;
	int *b1=(int *)b;
	if(*a1!=*b1) return *b1-*a1;
    else return 0;
}
void work(int*a,int n ){
	int i=0;
	for(;i<n-1;i++){
		if(a[i]!=a[i+1]) printf("%d ",a[i]);
		else break;
	}
	if(a[i]!=a[i-1]) printf("%d ",a[i]);
}
int main(){
int a[1000];
	char c,s;
	int i = 0;
	int n = 0;
	while ((c = getchar()) != '\n')
	{
		if (isdigit(c))
		{
			ungetc(c, stdin);//将c送回输入流
			scanf("%d", &a[n++]);
		}	
	}
	switch(s){
		case 'A':qsort(a,n,sizeof(int),cmpup);
		work(a,n);
		break;
		case 'D':qsort(a,n,sizeof(int),cmpup);
		work(a,n);
		break;	
	}
	
return 0;
}
