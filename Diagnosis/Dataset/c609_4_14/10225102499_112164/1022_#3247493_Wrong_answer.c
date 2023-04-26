#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[100];
    char yuming[50];
}address;

int cmp(const void* A,const void* B){
	address *x=(address*)A, *y=(address*)B;
	if(strcmp(x->yuming,y->yuming)==0)
		return -strcmp(x->name,y->name);
	else return strcmp(x->yuming,y->yuming);
}

void scan(char* s){
	int i=0;
	char a;
	a=getchar();
	while(a!='@'){
		s[i]=a;
		i++;
		a=getchar();
	}
}

int main()
{   address a[100];
    int n,i,j,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scan(a[i].name);
    	scanf("%s",a[i].yuming);     
    }
    qsort(a,n,sizeof(address),cmp);
    for(i=0;i<n;i++)
    printf("%s@%s",a[i].name,a[i].yuming);
    return 0;
}