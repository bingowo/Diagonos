#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char s;
	int n;
}ABC;
int check(char s[])
{
	char a[26]={' '};
	const char a[0]=s[0];
	for(int i=1;i<strlen(s);i++){
		int j=0;
		while(a[j]!=' '){
			if(s[i]!=a[j])j++;
			}
		if(a[j]==' ') a[j]=s[i];
		}
	for(int i=0;i<26;i++){
		if(a[i]==' ')break;
	}
	return i;
}

ABC* input(int m)
{
	ABC *p=(ABC*) malloc(sizeof(ABC)*m);
	for(int i=0;i<m;i++){
		scanf("%s",(p+i)->s);
		(p+i)->n=check(s);
	}
	return p;
}
int cmp(const void*a,const void*b)
{
	ABC *x=(ABC*)a;
	ABC *y=(ABC*)b;
	int c=x->n;
	int d=x->n; 
	if(c-d){
		if(c>d)return d-c;
		else return c-d;
	}
	else{
		return strcmp(x->s,y->s);
	}
}
void sort(ABC *a,int n)
{
	qsort(a,n,sizeof(ABC),cmp);
}
int main()
{
	ABC *a=NULL;
	int t;scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;scanf("%d",&n);
		a=input(n);//输入数据和字符个数都准备妥当 
		sort(a,n);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++){
			printf()
		}	
	}
}